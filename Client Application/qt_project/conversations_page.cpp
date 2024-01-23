#include "conversations_page.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QScrollBar>
#include <cerrno>
#include <QString>

conversations_page::conversations_page(QWidget* parent) : QDialog(parent), ui(new Ui::conversations_page) {
    ui->setupUi(this);

    connect(ui->scrollbar_conversation, &QScrollBar::valueChanged, this, &conversations_page::update_vertical_scrollbar);

    update_users();
	create_thread_for_listening();
	ui->conversation_with_user->setReadOnly(true);
}

void conversations_page::on_users_list_itemDoubleClicked(QListWidgetItem* item) {
	pthread_mutex_lock(&conv_page_mutex);
	if (write(get_sd(), &STOP_LISTEN, sizeof(STOP_LISTEN)) < 0) {
		qDebug() << "write";
		exit errno;
	}
	pthread_mutex_unlock(&conv_page_mutex);
	pthread_join(thread_id, nullptr);

	QString user = item->text();
	strcpy(get_last_user_opened(), user.toStdString().c_str());
	if (write(get_sd(), &OPEN, sizeof(OPEN)) < 0) {
		qDebug() << "write";
		exit errno;
	}

	if (write(get_sd(), get_last_user_opened(), sizeof(get_last_user_opened())) < 0) {
		qDebug() << "write";
		exit errno;
	}

	char message_list[MESSAGE_SIZE * 2];
	if (read(get_sd(), message_list, sizeof(message_list)) < 0) {
		qDebug() << "read";
		exit errno;
	}
	reply_ids.clear();

	//get the id of each message
	std::string msg_list = message_list;
	std::string new_msg_list;
	int i = 0;
	std::string message;
	while (i < msg_list.length()) {
		int new_line_pos = (int) msg_list.find_first_of('\n', i);
		if (new_line_pos != std::string::npos) {
			message = msg_list.substr(i, new_line_pos - i);
			reply_ids.push_back(message);
			i = new_line_pos + 1;
		}
		else {
			message = msg_list.substr(i);
			reply_ids.push_back(message);
			break;
		}
	}
	for (i = 0; i < reply_ids.size(); i++) {
		new_msg_list.append(std::to_string(i + 1) + ". " + reply_ids[i] + '\n');
	}
	ui->conversation_with_user->setPlainText(QString(new_msg_list.c_str()));
	ui->conversation_with_user->verticalScrollBar()->setValue(
			ui->conversation_with_user->verticalScrollBar()->maximum());
	create_thread_for_listening();
}

void conversations_page::update_users() {
	ui->users_list->clear();

	struct user_data {
		char user[USER_SIZE]{};
		bool logged{};
		int sd{};
	} usernames_to_send{};

	int number_of_users{};
	if (read(get_sd(), &number_of_users, sizeof(number_of_users)) == -1) {
		perror("read");
		exit(errno);
	}

	for (int i = 0; i < number_of_users - 1; i++) {
		if (read(get_sd(), &usernames_to_send, sizeof(usernames_to_send)) == -1) {
			perror("read");
			exit(errno);
		}
		auto user_in_list = new QListWidgetItem(usernames_to_send.user);
		user_in_list->setTextAlignment(Qt::AlignCenter);
		QFont font("Inter", 20);
		user_in_list->setFont(font);
		user_in_list->setForeground(usernames_to_send.logged ? QColor(Qt::green) : QColor(Qt::red));
		ui->users_list->addItem(user_in_list);
	}
	if (read(get_sd(), get_username(), USER_SIZE) == -1) {
		perror("read");
		exit(errno);
	}
}

conversations_page::~conversations_page() {
    delete ui;
}

void conversations_page::on_reply_button_clicked() {
	std::string reply_id_text = ui->reply_number_text->toPlainText().toStdString();
    std::string message_from_field = ui->message_field->text().toStdString();
	if (message_from_field.size() > MESSAGE_SIZE) {
		QMessageBox::warning(this, "Reply", "The message you entered is too long.");
		return;
	}
    if (reply_id_text.empty() || message_from_field.empty()) return;
    std::string reply = std::string(get_last_user_opened()) + ":" + "[" + std::string(get_username()) + "]" +
                    " replied to message with id: " + ui->reply_number_text->toPlainText().toStdString()
                        + "-> " + message_from_field;
    int reply_id = stoi(reply_id_text);
	if (reply_id > reply_ids.size() || reply_id < 1) {
		QMessageBox::warning(this, "Reply", "The message id you entered is invalid.");
		return;
	}
    char reply_to_send[MESSAGE_SIZE];
    strcpy(reply_to_send, reply.c_str());

    if (write(get_sd(), &REPLY, sizeof(REPLY)) == -1) {
        qDebug() << "write";
        exit(errno);
    }

    if (write(get_sd(), reply_to_send, sizeof(reply_to_send)) == -1) {
        qDebug() << "write";
        exit(errno);
    }
    reply = reply.substr(reply.find_first_of(':') + 1).append("\n");
    QString conversation = ui->conversation_with_user->toPlainText();
    reply_ids.push_back(reply);
    conversation.append((std::to_string(reply_ids.size()) + '.' + reply).c_str());
    ui->conversation_with_user->setPlainText(conversation);
    ui->message_field->clear();
    ui->conversation_with_user->verticalScrollBar()->setValue(
        ui->conversation_with_user->verticalScrollBar()->maximum());
	ui->reply_number_text->clear();
}

void conversations_page::on_send_button_clicked() {
	std::string message_text = ui->message_field->text().toStdString();
    if (message_text.empty()) {
        return;
    }
	if (message_text.size() > MESSAGE_SIZE) {
		QMessageBox::warning(this, "Send", "The message you entered is too long.");
		return;
	}
    char message_to_send[MESSAGE_SIZE];
    strcpy(message_to_send, get_last_user_opened());
    strcat(message_to_send, ":");
    strcat(message_to_send, message_text.c_str());

    if (write(get_sd(), &SEND, sizeof(SEND)) == -1) {
        qDebug() << "write";
        exit(errno);
    }

    if (write(get_sd(), message_to_send, strlen(message_to_send) + 1) == -1) {
        qDebug() << "write";
        exit(errno);
    }
    char message[MESSAGE_SIZE]{};
    strcat(message, get_username());
    strcat(message, ": ");
    strcat(message, ui->message_field->text().toStdString().c_str());
    strcat(message, "\n");

    QString conversation = ui->conversation_with_user->toPlainText();
    reply_ids.emplace_back(message);
    conversation += std::to_string(reply_ids.size()) + '.' + message;

    pthread_mutex_lock(&conv_page_mutex);
    ui->conversation_with_user->setPlainText(conversation);
    ui->message_field->clear();
    ui->reply_number_text->clear();
    ui->conversation_with_user->verticalScrollBar()->setValue(
        ui->conversation_with_user->verticalScrollBar()->maximum());
    pthread_mutex_unlock(&conv_page_mutex);
}

void conversations_page::listen_for_new_messages(conversations_page* cp) {
	while (true) {
		char message[MESSAGE_SIZE] = "";
		if (read(get_sd(), message, MESSAGE_SIZE) > 0) {
			if (is_message(message)) {
				pthread_mutex_lock(&cp->conv_page_mutex);
				bool reply = (message[0] == '[');
				cp->reply_ids.emplace_back(message);
				std::string possible_user = reply ? "" : std::string(get_last_user_opened()) + ": ";
				std::string formatted_message = format_message(cp->reply_ids.size(), message, possible_user);
				cp->ui->conversation_with_user->append(QString((formatted_message).c_str()));
				cp->ui->conversation_with_user->verticalScrollBar()->setValue(
						cp->ui->conversation_with_user->verticalScrollBar()->maximum());
				pthread_mutex_unlock(&cp->conv_page_mutex);
			}
			else if (strstr(message, "login ") != nullptr) {
				char username[USER_SIZE]{};
				strcpy(username, message + strlen("login "));
				auto user = cp->ui->users_list->findItems(QString(username), Qt::MatchExactly);
				user[0]->setForeground(QColor(Qt::green));
			}
			else if (strstr(message, "logout ") != nullptr) {
				char username[USER_SIZE]{};
				strcpy(username, message + strlen("logout "));
				auto user = cp->ui->users_list->findItems(QString(username), Qt::MatchExactly);
				user[0]->setForeground(QColor(Qt::red));
			}
			else if (strstr(message, "register ") != nullptr) {
				char username[USER_SIZE]{};
				strcpy(username, message + strlen("register "));
				auto user = new QListWidgetItem(username);
				user->setTextAlignment(Qt::AlignCenter);
				QFont font("Inter", 20);
				user->setFont(font);
				user->setForeground(QColor(Qt::red));
				cp->ui->users_list->addItem(user);
			}
			else if (strcmp(message, "stop_listen") == 0) {
				break;
			}
			else {
				continue;
			}
		}
	}
}

bool conversations_page::is_message(char* message) {
	return strcmp(message, "done") != 0 && strcmp(message, "stop_listen") != 0 &&
				strstr(message, "login") == nullptr && strstr(message, "logout") == nullptr
				&& strstr(message, "register") == nullptr;
}

void conversations_page::create_thread_for_listening() {
    pthread_create(&thread_id, nullptr, listen_in_new_thread, this);
}

void* conversations_page::listen_in_new_thread(void* arg) {
	auto cp = (conversations_page*) arg;
	listen_for_new_messages(cp);
	return nullptr;
}

void conversations_page::update_vertical_scrollbar() {
    auto scrollbar = ui->conversation_with_user->verticalScrollBar();
    scrollbar->setRange(0, (int)ui->conversation_with_user->document()->size().height());
    scrollbar->hide();
}

void conversations_page::on_logout_button_clicked() {
    QMessageBox::warning(this, "Logout", "You have been logged out.");
    if (write(get_sd(), &QUIT, sizeof(QUIT)) < 0) {
        qDebug() << "write";
        exit errno;
    }
    this->accept();
}

void conversations_page::closeEvent(QCloseEvent* event) {
	this->on_logout_button_clicked();
}

std::string conversations_page::format_message(int size, char* message, std::string& possible_user) {
	return std::to_string(size) + '.' + possible_user + message + '\n';
}
