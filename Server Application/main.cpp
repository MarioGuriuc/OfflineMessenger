#include "handle_clients_logic.h"

void intialize_database() {
	char* error_message = nullptr;
	int result = sqlite3_open("users.db", &database);
	if (result != SQLITE_OK) {
		sqlite3_close(database);
		exit(errno);
	}
	std::string sql = "CREATE TABLE IF NOT EXISTS users ("
					  "username TEXT NOT NULL,"
					  "password TEXT NOT NULL,"
					  "logged BOOLEAN NOT NULL DEFAULT 0,"
					  "sd INTEGER NOT NULL DEFAULT 0,"
					  "conv_open TEXT DEFAULT NULL);";
	result = sqlite3_exec(database, sql.c_str(), nullptr, nullptr, &error_message);
	if (result != SQLITE_OK) {
		sqlite3_free(error_message);
		sqlite3_close(database);
		exit(errno);
	}
	sql = "CREATE TABLE IF NOT EXISTS messages("
		  "from_user TEXT NOT NULL,"
		  "to_user TEXT NOT NULL,"
		  "message TEXT NOT NULL,"
		  "timestamp TEXT NOT NULL);";
	result = sqlite3_exec(database, sql.c_str(), nullptr, nullptr, &error_message);
	if (result != SQLITE_OK) {
		sqlite3_free(error_message);
		sqlite3_close(database);
		exit(errno);
	}
	sqlite3_close(database);
}

int main() {
	intialize_database();
	sockaddr_in server{}, from{};
	int sd;

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == - 1) {
		perror("socket\n");
		exit errno;
	}

	int on = 1;
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);

	if (bind(sd, (sockaddr*) &server, sizeof(sockaddr)) == - 1) {
		perror("bind\n");
		exit(errno);
	}

	if (listen(sd, 5) == - 1) {
		perror("listen\n");
		exit(errno);
	}

	while (true) {
		int client_sd;
		socklen_t length = sizeof(from);
		client_sd = accept(sd, (sockaddr*) &from, &length);
		if (client_sd < 0) {
			perror("accept\n");
			continue;
		}
		threads.emplace_back(sd, pthread_t());
		if (pthread_create(&threads[threads_nr++].second, nullptr, handle_client, &client_sd) != 0) {
			perror("thread\n");
			exit errno;
		}
	}
}