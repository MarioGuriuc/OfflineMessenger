#include <QMessageBox>
#include "login_or_register_page.h"
#include "ui_login_or_register_page.h"
#include "conversations_page.h"
#include "mainwindow.h"

login_or_register_page::login_or_register_page(QWidget *parent) : QDialog(parent), ui(new Ui::login_or_register_page) {
	sockaddr_in server{};

	if ((get_sd() = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		exit errno;
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(ADDRESS);
	server.sin_port = htons(PORT);

	if (::connect(get_sd(), (sockaddr*) &server, sizeof(sockaddr)) == -1) {
		exit errno;
	}

    ui->setupUi(this);
}

login_or_register_page::~login_or_register_page() {
    delete ui;
}

void login_or_register_page::on_login_button_clicked() {
	if (write(get_sd(), &LOGIN, sizeof(LOGIN)) < 0) {
		perror("write");
		exit errno;
	}
	auto username = ui->username_text->text();
	auto password = ui->password_text->text();
	std::string user = username.toStdString().append(" ");
	std::string pass = password.toStdString();
	char user_and_pass[USER_SIZE * 2];
	std::string username_and_password = user + pass;
	strcpy(user_and_pass, username_and_password.c_str());

	if (write(get_sd(), user_and_pass, USER_SIZE) < 0) {
		perror("write");
		exit errno;
	}

	enum response response;
	if (read(get_sd(), &response, sizeof(response)) < 0) {
		perror("read");
		exit errno;
	}

	switch (response) {
		case response::UAPE: {
			QMessageBox::warning(this, "Login", "The username and password can not be empty.");
			break;
		}
		case response::PE: {
			QMessageBox::warning(this, "Login", "The password can not be empty.");
			break;
		}
		case response::UE: {
			QMessageBox::warning(this, "Login", "The username can not be empty.");
			break;
		}
		case response::UAL: {
			QMessageBox::warning(this, "Login", "The user is already logged in.");
			break;
		}
		case response::UDE: {
			QMessageBox::warning(this, "Login", "The user does not exist.");
			break;
		}
		case response::WP: {
			QMessageBox::warning(this, "Login", "The password is wrong.");
			break;
		}
		default: {
			QMessageBox::information(this, "Login", "You have successfully logged in.");
			auto cp = new conversations_page(this);
			this->hide();
			int result = cp->exec();
			if (result == QDialog::Accepted) {
				cp->deleteLater();
				this->reject();
			}
			break;
		}
	}
}

void login_or_register_page::on_register_button_clicked() {
    auto username = ui->username_text->text().toStdString();
    if (username.size() < 5) {
        QMessageBox::warning(this, "Register", "The username must have at least 5 characters.");
        return;
    }
    auto password = ui->password_text->text().toStdString();
    if (password.size() < 5) {
        QMessageBox::warning(this, "Register", "The password must have at least 5 characters.");
        return;
    }

    if (write(get_sd(), &REGISTER, sizeof(REGISTER)) < 0) {
        perror("write");
        exit(0);
    }

    std::string user = username;
    user.append(" ");
    std::string pass = password;
    char user_and_pass[USER_SIZE * 2];
    std::string username_and_password = user + pass;
    strcpy(user_and_pass, username_and_password.c_str());

    if (write(get_sd(), user_and_pass, sizeof(user_and_pass)) < 0) {
        perror("write");
        exit(0);
    }

    bool registered;

    if (read(get_sd(), &registered, sizeof(registered)) < 0) {
        perror("read");
        exit(0);
    }

    if (registered) {
        QMessageBox::warning(this, "Register", "The user is already registered.");
    }
    else {
        QMessageBox::information(this, "Register", "You have registered successfully.");
    }
}

void login_or_register_page::on_back_button_clicked() {
	this->reject();
}

