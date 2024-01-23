#include <sys/socket.h>
#include <netinet/in.h>
#include <cerrno>
#include <unistd.h>
#include <cstring>
#include <string>
#include <unordered_map>
#include <pthread.h>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <list>
#include <sqlite3.h>

#define PORT 2024
#define MESSAGE_SIZE 2048
#define USER_SIZE 64

static sqlite3* database;
static std::vector<std::pair<int, pthread_t>> threads; // threads for the clients to allow concurrency
static unsigned int threads_nr; // number of threads
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //mutex for synchronization

enum COMMANDS {
	REGISTER,
	LOGIN,
	REPLY,
	OPEN,
	SEND,
	STOP_LISTEN,
	QUIT,
	EXIT
};

enum response_for_login {
	UAPE, //username and password empty
	PE, //password empty
	UE, //username empty
	UAL, //user already logged in
	UDE, //user doesn't exist
	WP, //wrong password
	PM //password matches
};

//functions declarations
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool user_registered(std::string& username);

bool user_exists(std::string& username);

bool password_matches(std::string& username, std::string& password);

void disconnect_client(int sd);

bool another_client_logged(std::string& username);

std::string recieve_message_from_user(int sd);

void send_message_list_to_user(std::string& user_to_send, std::string& user_from, int sd);

void send_users_to_client(int sd);

void send_message_to_other_user(int sd);

void open_conversation(int sd);

void notify_other_clients(std::string& username, enum COMMANDS action);

void handle_login_or_register(int command, int sd);

int process_command(int command, int sd);

void stop_listening(int sd);

int quit(int sd);

void* handle_client(void* sd_arg);

int find_sd_for_conv_open(int& sd, std::string& username_from_client, std::string& username_to_send);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////