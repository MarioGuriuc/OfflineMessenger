/********************************************************************************
** Form generated from reading UI file 'users_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_PAGE_H
#define UI_USERS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_users_page
{
public:
    QScrollArea *users_scroll_area;
    QWidget *scrollAreaWidgetContents;
    QListWidget *users_list;

    void setupUi(QDialog *users_page)
    {
        if (users_page->objectName().isEmpty())
            users_page->setObjectName(QString::fromUtf8("users_page"));
        users_page->resize(640, 480);
        users_page->setCursor(QCursor(Qt::CrossCursor));
        users_scroll_area = new QScrollArea(users_page);
        users_scroll_area->setObjectName(QString::fromUtf8("users_scroll_area"));
        users_scroll_area->setGeometry(QRect(0, -10, 641, 491));
        QPalette palette;
        QBrush brush(QColor(173, 127, 168, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        users_scroll_area->setPalette(palette);
        users_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 639, 489));
        users_list = new QListWidget(scrollAreaWidgetContents);
        users_list->setObjectName(QString::fromUtf8("users_list"));
        users_list->setGeometry(QRect(110, 50, 391, 381));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        users_list->setPalette(palette1);
        QFont font;
        font.setPointSize(14);
        users_list->setFont(font);
        users_scroll_area->setWidget(scrollAreaWidgetContents);

        retranslateUi(users_page);

        QMetaObject::connectSlotsByName(users_page);
    } // setupUi

    void retranslateUi(QDialog *users_page)
    {
        users_page->setWindowTitle(QApplication::translate("users_page", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class users_page: public Ui_users_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_PAGE_H
