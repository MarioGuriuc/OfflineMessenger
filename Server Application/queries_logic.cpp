#include "queries_logic.h"

int callback_for_int(void* data, int argc, char* argv[], char* col_names[]) {
	int* result = (int*)(data);
	*result = std::stoi(argv[0]);
	return 0;
}

int callback_for_users(void* data, int argc, char** argv, char** col_names) {
	struct user_data {
		char user[USER_SIZE]{};
		bool logged{};
		int sd{};
	};
	auto users = (std::vector<user_data>*)data;
	user_data usernames_to_send{};
	std::string username = argv[0];
	strcpy(usernames_to_send.user, username.c_str());
	usernames_to_send.logged = std::stoi(argv[1]);
	usernames_to_send.sd = std::stoi(argv[2]);
	users->emplace_back(usernames_to_send);
	return 0;
}

int callback_for_connected_users(void* data, int argc, char** argv, char** col_names) {
	auto clients = (std::vector<int>*)data;
	clients->emplace_back(std::stoi(argv[0]));
	return 0;
}

int callback_for_username(void* data, int argc, char** argv, char** col_names) {
	auto username = (std::string*)(data);
	*username = argv[0];
	return 0;
}

int callback_for_messages(void* data, int argc, char* argv[], char* col_names[]) {
	char* msg_list = (char*)(data);
	std::string from_user = argv[0];
	std::string to_user = argv[1];
	std::string message = argv[2];
	std::string msg;
	if (message[0] != '[') {
		msg = from_user + ": " + message + "\n";
	}
	else {
		msg = message + "\n";
	}
	strcat(msg_list, msg.c_str());
	return 0;
}

int execute_simple_query(std::string& sql) {
	sqlite3_open("users.db", &database);
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), nullptr, nullptr, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
	return 0;
}

int execute_simple_query_int(std::string& sql) {
	sqlite3_open("users.db", &database);
	int sd{};
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), callback_for_int, &sd, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
	return sd;
}

void execute_query_for_get_connected_users(std::string& sql, std::vector<int>& clients) {
	sqlite3_open("users.db", &database);
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), callback_for_connected_users, &clients, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
}

void execute_query_for_get_users(std::string& sql, void* usernames) {
	sqlite3_open("users.db", &database);
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), callback_for_users, usernames, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
}

void execute_query_for_get_username(std::string& sql, void* username) {
	sqlite3_open("users.db", &database);
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), callback_for_username, username, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
}

void execute_query_for_get_messages(std::string& sql, void* msg_list) {
	sqlite3_open("users.db", &database);
	char* err_msg;
	int rc = sqlite3_exec(database, sql.c_str(), callback_for_messages, msg_list, &err_msg);
	if (rc != SQLITE_OK) {
		sqlite3_free(err_msg);
	}
	sqlite3_close(database);
}

bool query_user_registered(const std::string& username, const std::string& sql) {
	bool result{};
	sqlite3_open("users.db", &database);
	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr);
	if (rc == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, username.c_str(), -1, nullptr);
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			result = sqlite3_column_int(stmt, 0) == 1;
		}
		sqlite3_finalize(stmt);
	}
	sqlite3_close(database);
	return result;
}

bool query_user_exists(const std::string& username, const std::string& sql) {
	bool result{};
	sqlite3_open("users.db", &database);
	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr);
	if (rc == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, username.c_str(), -1, nullptr);
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			result = sqlite3_column_int(stmt, 0) == 1;
		}
		sqlite3_finalize(stmt);
	}
	sqlite3_close(database);
	return result;
}

bool query_password_matches(const std::string& username, const std::string& password, const std::string& sql) {
	bool result{};
	sqlite3_open("users.db", &database);
	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr);
	if (rc == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, username.c_str(), -1, nullptr);
		sqlite3_bind_text(stmt, 2, password.c_str(), -1, nullptr);
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			result = sqlite3_column_int(stmt, 0) == 1;
		}
		sqlite3_finalize(stmt);
	}
	sqlite3_close(database);
	return result;
}

int query_another_client_logged(const std::string& username, const std::string& sql) {
	int logged{};
	sqlite3_open("users.db", &database);
	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr);
	if (rc == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, username.c_str(), -1, nullptr);
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			logged = sqlite3_column_int(stmt, 0);
		}
		sqlite3_finalize(stmt);
	}
	sqlite3_close(database);
	return logged;
}