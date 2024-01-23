#include <iostream>
#include "queries_logic.h"

bool user_registered(std::string& username) {
	std::string sql = "SELECT COUNT(*) FROM users WHERE username = ?;";
	bool result;
	pthread_mutex_lock(&mutex);
	result = query_user_registered(username, sql);
	pthread_mutex_unlock(&mutex);
	return result;
}

bool user_exists(std::string& username) {
	std::string sql = "SELECT count(username) FROM users WHERE username = ?;";
	bool result;
	pthread_mutex_lock(&mutex);
	result = query_user_exists(username, sql);
	pthread_mutex_unlock(&mutex);
	return result;
}

bool password_matches(std::string& username, std::string& password) {
	std::string sql =
			"SELECT COUNT(*) FROM users WHERE username = ? AND password = ?;";
	bool result;
	pthread_mutex_lock(&mutex);
	result = query_password_matches(username, password, sql);
	pthread_mutex_unlock(&mutex);
	return result;
}

void disconnect_client(int sd) {
	stop_listening(sd);
	printf("Client with id: %d has logged out.\n", sd);
	std::string username;
	std::string sql = "SELECT username FROM users WHERE sd = " + std::to_string(sd) + ";";
	pthread_mutex_lock(&mutex);
	execute_query_for_get_username(sql, &username);
	pthread_mutex_unlock(&mutex);
	sql = "UPDATE users SET logged = 0, sd = 0 WHERE sd = " + std::to_string(sd) + ";";
	pthread_mutex_lock(&mutex);
	execute_simple_query(sql);
	pthread_mutex_unlock(&mutex);
	notify_other_clients(username, QUIT);
}

bool another_client_logged(std::string& username) {
	int logged;
	std::string sql = "SELECT logged FROM users WHERE username = ?;";
	pthread_mutex_lock(&mutex);
	logged = query_another_client_logged(username, sql);
	pthread_mutex_unlock(&mutex);
	return logged == 1;
}

int find_sd_for_conv_open(int& sd, std::string& username_from_client, std::string& username_to_send) {
	std::string sql = "SELECT sd FROM users WHERE username = '" + username_to_send + "' AND conv_open = '" +
			username_from_client + "';";
	pthread_mutex_lock(&mutex);
	sd = execute_simple_query_int(sql);
	pthread_mutex_unlock(&mutex);
	return sd;
}

int process_command(int command, int sd) {
	switch (command) {
		case COMMANDS::LOGIN: {
			handle_login_or_register(LOGIN, sd);
			break;
		}
		case COMMANDS::REGISTER: {
			handle_login_or_register(REGISTER, sd);
			break;
		}
		case COMMANDS::OPEN: {
			open_conversation(sd);
			break;
		}
		case COMMANDS::SEND:
		case COMMANDS::REPLY: {
			send_message_to_other_user(sd);
			break;
		}
		case COMMANDS::STOP_LISTEN: {
			stop_listening(sd);
			break;
		}
		case COMMANDS::QUIT: {
			return quit(sd);
		}
		default: break;
	}
	return 0;
}

void stop_listening(int sd) {
	std::string sql = "UPDATE users SET conv_open = NULL WHERE sd = " + std::to_string(sd) + ";";
	pthread_mutex_lock(&mutex);
	execute_simple_query(sql);
	pthread_mutex_unlock(&mutex);
	if (write(sd, "stop_listen", sizeof("stop_listen")) < 0) {
		perror("write\n");
		exit errno;
	}
}

int quit(int sd) {
	disconnect_client(sd);
	for (auto it = threads.begin(); it != threads.end(); it++) {
		if (it->first == sd) {
			threads.erase(it);
			break;
		}
	}
	close(sd);
	return EXIT;
}

void* handle_client(void* sd_arg) {
	pthread_detach(pthread_self());
	int sd = *(int*)sd_arg;
	printf("Client with id %d has connected.\n", sd);
	while (true) {
		enum COMMANDS command{};
		if (read(sd, &command, sizeof(command)) < 0) {
			perror("read");
			exit errno;
		}
		if (process_command(command, sd) == COMMANDS::EXIT) {
			break;
		}
	}
	printf("Client with id: %d has quit the server.\n", sd);
	return nullptr;
}

void handle_login_or_register(int option, int sd) {
	char username_and_password[USER_SIZE * 2];
	if (read(sd, username_and_password, sizeof(username_and_password)) < 0) {
		perror("read");
		exit errno;
	}
	std::string user_and_pass = username_and_password;
	std::string username = user_and_pass.substr(0, user_and_pass.find_first_of(' '));
	std::string password = user_and_pass.substr(user_and_pass.find_first_of(' ') + 1);
	switch (option) {
		case REGISTER: {
			bool registered = user_registered(username);
			if (registered) {
				if (write(sd, &registered, sizeof(registered)) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else {
				std::string sql =
						"INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "');";
				pthread_mutex_lock(&mutex);
				execute_simple_query(sql);
				pthread_mutex_unlock(&mutex);
				if (write(sd, &registered, sizeof(registered)) < 0) {
					perror("write\n");
					exit errno;
				}
				notify_other_clients(username, REGISTER);
			}
			break;
		}
		case LOGIN: {
			enum response_for_login responses[] = {UAPE, PE, UE, UAL, UDE, WP, PM};

			if (username.empty() && password.empty()) {
				if (write(sd, &responses[0], sizeof(responses[0])) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else if (username.empty()) {
				if (write(sd, &responses[2], sizeof(responses[2])) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else if (password.empty()) {
				if (write(sd, &responses[1], sizeof(responses[1])) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else if (another_client_logged(username)) {
				if (write(sd, &responses[3], sizeof(responses[3])) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else if (!user_exists(username)) {
				if (write(sd, &responses[4], sizeof(responses[4])) < 0) {
					perror("write\n");
					exit errno;
				}
			}
			else {
				if (password_matches(username, password)) {
					if (write(sd, &responses[6], sizeof(responses[6])) < 0) {
						perror("write\n");
						exit errno;
					}
					std::string sql =
							"UPDATE users SET logged = 1, sd = " + std::to_string(sd) + " WHERE username = '" +
							username + "';";
					pthread_mutex_lock(&mutex);
					execute_simple_query(sql);
					pthread_mutex_unlock(&mutex);
					send_users_to_client(sd);
					notify_other_clients(username, LOGIN);
				}
				else {
					if (write(sd, &responses[5], sizeof(responses[5])) < 0) {
						perror("write\n");
						exit errno;
					}
				}
			}
			break;
		}
		default: break;
	}
}

void notify_other_clients(std::string& username, enum COMMANDS action) {
	std::string sql = "SELECT sd FROM users WHERE logged = 1 AND username != '" + username + "';";
	std::vector<int> clients;
	pthread_mutex_lock(&mutex);
	execute_query_for_get_connected_users(sql, clients);
	pthread_mutex_unlock(&mutex);
	char user[USER_SIZE];
	strcpy(user, username.c_str());
	std::string action_str;
	switch (action) {
		case LOGIN: {
			action_str = "login ";
			break;
		}
		case REGISTER: {
			action_str = "register ";
			break;
		}
		case QUIT: {
			action_str = "logout ";
			break;
		}
		default: break;
	}
	for (const auto& it : clients) {
		char NOTIFY[USER_SIZE];
		strcpy(NOTIFY, action_str.c_str());
		strcat(NOTIFY, user);
		if (write(it, NOTIFY, sizeof(NOTIFY)) < 0) {
			perror("write\n");
			exit errno;
		}
	}
}

void open_conversation(int sd) {
	char username[USER_SIZE];
	if (read(sd, username, sizeof(username)) < 0) {
		perror("read\n");
		exit errno;
	}
	std::string user_with_conv = username;
	std::string user_to_send;
	std::string sql = "SELECT username FROM users WHERE sd = " + std::to_string(sd) + ";";
	pthread_mutex_lock(&mutex);
	execute_query_for_get_username(sql, &user_to_send);
	sql = "UPDATE users SET conv_open = '" + user_with_conv + "' WHERE sd = " + std::to_string(sd) + ";";
	execute_simple_query(sql);
	pthread_mutex_unlock(&mutex);
	send_message_list_to_user(user_with_conv, user_to_send, sd);
}

void send_users_to_client(int sd) {
	std::string username; //username from the client who requested the users list
	struct user_data {
		char user[USER_SIZE];
		bool logged;
		int sd;
	} usernames_to_send{};
	std::vector<user_data> usernames;
	std::string sql = "SELECT username, logged, sd FROM users;";
	pthread_mutex_lock(&mutex);
	execute_query_for_get_users(sql, &usernames);
	pthread_mutex_unlock(&mutex);
	int number_of_users = (int)usernames.size();
	if (write(sd, &number_of_users, sizeof(number_of_users)) < 0) {
		perror("write\n");
		exit errno;
	}
	int i = 0;
	for (const auto& it : usernames) {
		if (i == number_of_users) break;
		if (it.sd == sd) {
			username = it.user; continue;
		}
		strcpy(usernames_to_send.user, it.user);
		usernames_to_send.logged = it.logged;
		usernames_to_send.sd = it.sd;
		if (write(sd, &usernames_to_send, sizeof(usernames_to_send)) < 0) {
			perror("write\n");
			exit errno;
		}
		i++;
	}
	//the last user is the one who requested the list
	if (write(sd, username.c_str(), username.size() + 1) < 0) {
		perror("write\n");
		exit errno;
	}
}

void send_message_list_to_user(std::string& user_with_conv, std::string& user_to_send, int sd) {
	char msg_list[MESSAGE_SIZE * 2] = "";
	std::string sql = "SELECT from_user,"
					  " to_user,"
					  " message"
					  " FROM messages WHERE "
					  "(from_user = '" + user_with_conv + "' AND to_user = '" + user_to_send + "') OR "
					  "(from_user = '" + user_to_send + "' AND to_user = '" + user_with_conv + "') order by timestamp ASC;";
	pthread_mutex_lock(&mutex);
	execute_query_for_get_messages(sql, msg_list);
	pthread_mutex_unlock(&mutex);
	if (write(sd, msg_list, sizeof(msg_list)) < 0) {
		perror("write\n");
		exit errno;
	}
}

std::string recieve_message_from_user(int sd) {
	char message[MESSAGE_SIZE];
	if (read(sd, message, MESSAGE_SIZE) < 0) {
		perror("read\n");
		exit errno;
	}
	return {message};
}

void send_message_to_other_user(int sd) {
	std::string username_from_client;
	std::string sql = "SELECT username FROM users WHERE sd = " + std::to_string(sd) + ";";
	pthread_mutex_lock(&mutex);
	execute_query_for_get_username(sql, &username_from_client);
	pthread_mutex_unlock(&mutex);
	std::string received_message = recieve_message_from_user(sd);
	int client_to_send{};
	std::string username_to_send = received_message.substr(0, received_message.find_first_of(':'));
	find_sd_for_conv_open(client_to_send, username_from_client, username_to_send);
	std::string message_without_username = received_message.substr(received_message.find_first_of(':') + 1);
	if (client_to_send != 0) { //if the client has the conversation opened, we also send them the message for display
		char message[MESSAGE_SIZE];
		strcpy(message, message_without_username.c_str());
		if (write(client_to_send, message, sizeof(message)) < 0) {
			perror("write");
			exit errno;
		}
	}
	// inserting the messages in the database
	sql = "INSERT INTO messages (from_user, to_user, message, timestamp)"
		  "VALUES "
		  "('" + username_from_client + "', '" + username_to_send + "', '" + message_without_username +
		  "', datetime('now'));";
	pthread_mutex_lock(&mutex);
	execute_simple_query(sql);
	pthread_mutex_unlock(&mutex);
	if (write(sd, "done", sizeof("done")) < 0) {
		perror("write");
		exit errno;
	}
}