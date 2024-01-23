#ifndef USERS_PAGE_H
#define USERS_PAGE_H

#include "qlistwidget.h"
#include <QDialog>

namespace Ui {
class users_page;
}

class users_page : public QDialog {
Q_OBJECT

public:
	explicit users_page(QWidget* parent = nullptr);

	~users_page();

private slots:

	void on_users_list_itemDoubleClicked(QListWidgetItem* item);

	void on_logout_button_clicked();

private:
	Ui::users_page* ui;

	void update_users();

	int number_of_users;
};

#endif // USERS_PAGE_H
