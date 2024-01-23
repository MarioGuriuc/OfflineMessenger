#include "mainwindow.h"

#include <QApplication>

int sd;

char username[USER_SIZE];

char last_user_opened[USER_SIZE];

char* get_username() {
    return username;
}

char* get_last_user_opened() {
    return last_user_opened;
}

int& get_sd() {
    return sd;
}

int main(int argc, char* argv[]) {
    QApplication Messenger(argc, argv);
    MainWindow main_window;
    main_window.show();

    return QApplication::exec();
}
