#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QDialog>
#include "QDebug"

namespace Ui {
	class login_page;
}

class login_page : public QDialog {
Q_OBJECT

public:
	explicit login_page(QWidget* parent = nullptr);

	~login_page();

private slots:

	void on_back_button_clicked();

	void on_login_button_clicked();

private:
	Ui::login_page* ui;
	enum response {
		UAPE, //username and password empty
		PE, //password empty
		UE, //username empty
		UAL, //user already logged in
		UDE, //user doesn't exist
		WP //wrong password
	};
};

#endif // LOGIN_PAGE_H
