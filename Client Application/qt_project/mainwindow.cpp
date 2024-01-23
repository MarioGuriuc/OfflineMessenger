#include <QPointer>
#include "mainwindow.h"
#include "login_or_register_page.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if (write(get_sd(), &QUIT, sizeof(QUIT)) < 0) {
        perror("write");
        exit errno;
    }
    ::close(get_sd());
    exit(0);
}

void MainWindow::on_continue_button_clicked() {
    auto lrp = new login_or_register_page(this);
    this->hide();
    lrp->exec();
    this->show();
    lrp->deleteLater();
}

