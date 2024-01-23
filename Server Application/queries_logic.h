#include "handle_clients_logic.h"

///Callback functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int callback_for_int(void* data, int argc, char* argv[], char* col_names[]);

int callback_for_users(void* data, int argc, char** argv, char** col_names);

int callback_for_connected_users(void* data, int argc, char** argv, char** col_names);

int callback_for_username(void* data, int argc, char* argv[], char* col_names[]);

int callback_for_messages(void* data, int argc, char* argv[], char* col_names[]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////

///Functions for queries
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int execute_simple_query(std::string& sql);

int execute_simple_query_int(std::string& sql);

void execute_query_for_get_users(std::string& sql, void* usernames);

void execute_query_for_get_connected_users(std::string& sql, std::vector<int>& clients);

void execute_query_for_get_username(std::string& sql, void* username);

void execute_query_for_get_messages(std::string& sql, void* msg_list);

bool query_user_registered(const std::string& username, const std::string& sql);

bool query_user_exists(const std::string& username, const std::string& sql);

bool query_password_matches(const std::string& username, const std::string& password, const std::string& sql);

int query_another_client_logged(const std::string& username, const std::string& sql);
/////////////////////////////////////////////////////////////////////////////////////////////////////////