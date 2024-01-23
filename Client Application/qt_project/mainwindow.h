#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <QStackedWidget>
#include <QVBoxLayout>

enum COMMANDS {
	REGISTER_ENUM,
	LOGIN_ENUM,
	REPLY_ENUM,
	OPEN_ENUM,
	SEND_ENUM,
	STOP_LISTEN_ENUM,
	QUIT_ENUM
};

static enum COMMANDS LOGIN = LOGIN_ENUM;
static enum COMMANDS REGISTER = REGISTER_ENUM;
static enum COMMANDS REPLY = REPLY_ENUM;
static enum COMMANDS OPEN = OPEN_ENUM;
static enum COMMANDS SEND = SEND_ENUM;
static enum COMMANDS STOP_LISTEN = STOP_LISTEN_ENUM;
static enum COMMANDS QUIT = QUIT_ENUM;

#define MESSAGE_SIZE 2048
#define USER_SIZE 64
#define PORT 2024
#define ADDRESS "0"

int& get_sd();

char* get_username();

char* get_last_user_opened();

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

	~MainWindow();

private slots:

    void on_continue_button_clicked();

private:
	Ui::MainWindow* ui;

	void closeEvent(QCloseEvent* event) override;
};
#endif // MAINWINDOW_H
