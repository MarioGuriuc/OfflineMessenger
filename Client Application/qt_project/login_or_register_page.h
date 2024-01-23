#ifndef LOGIN_OR_REGISTER_PAGE_H
#define LOGIN_OR_REGISTER_PAGE_H

#include <QDialog>

namespace Ui {
class login_or_register_page;
}

class login_or_register_page : public QDialog {
    Q_OBJECT

public:
    explicit login_or_register_page(QWidget *parent = nullptr);
    ~login_or_register_page();

private slots:
	void on_login_button_clicked();

	void on_register_button_clicked();

	void on_back_button_clicked();

private:
	enum response {
		UAPE, //username and password empty
		PE, //password empty
		UE, //username empty
		UAL, //user already logged in
		UDE, //user doesn't exist
		WP //wrong password
	};
    Ui::login_or_register_page *ui;
};

#endif // LOGIN_OR_REGISTER_PAGE_H
