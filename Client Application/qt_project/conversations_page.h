#ifndef CONVERSATIONS_PAGE_H
#define CONVERSATIONS_PAGE_H

#include <QDialog>
#include "QDebug"
#include "qlistwidget.h"
#include "ui_conversations_page.h"

namespace Ui {
class conversations_page;
}

class conversations_page : public QDialog {
Q_OBJECT

public:
	explicit conversations_page(QWidget* parent = nullptr);

	~conversations_page();

private slots:

	void on_send_button_clicked();

	void on_reply_button_clicked();

    void on_users_list_itemDoubleClicked(QListWidgetItem *item);

    void on_logout_button_clicked();

private:
	Ui::conversations_page* ui;
	pthread_t thread_id;
	std::vector<std::string> reply_ids;
	pthread_mutex_t conv_page_mutex = PTHREAD_MUTEX_INITIALIZER;

	void create_thread_for_listening();

	static void* listen_in_new_thread(void*);

    void update_users();

	static void listen_for_new_messages(conversations_page*);

	void update_vertical_scrollbar();

	void closeEvent(QCloseEvent* event) override;

	static bool is_message(char* message);

	static std::string format_message(int, char*, std::string&);
};

#endif // CONVERSATIONS_PAGE_H
