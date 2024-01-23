/********************************************************************************
** Form generated from reading UI file 'conversations_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSATIONS_PAGE_H
#define UI_CONVERSATIONS_PAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_conversations_page
{
public:
    QGroupBox *groupBox;
    QTextEdit *conversation_with_user;
    QLineEdit *message_field;
    QPushButton *send_button;
    QScrollBar *scrollbar_conversation;
    QPushButton *reply_button;
    QTextEdit *reply_number_text;
    QLabel *label;
    QListWidget *users_list;
    QPushButton *logout_button;

    void setupUi(QDialog *conversations_page)
    {
        if (conversations_page->objectName().isEmpty())
            conversations_page->setObjectName(QString::fromUtf8("conversations_page"));
        conversations_page->setWindowModality(Qt::ApplicationModal);
        conversations_page->resize(640, 480);
        conversations_page->setMinimumSize(QSize(640, 480));
        conversations_page->setMaximumSize(QSize(640, 480));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(173, 127, 168, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 192, 248, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(214, 159, 208, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(86, 63, 84, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(115, 85, 112, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(214, 191, 211, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(86, 63, 84, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        QBrush brush11(QColor(225, 165, 218, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush11);
        conversations_page->setPalette(palette);
        conversations_page->setCursor(QCursor(Qt::CrossCursor));
        conversations_page->setModal(false);
        groupBox = new QGroupBox(conversations_page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-20, -20, 831, 531));
        conversation_with_user = new QTextEdit(groupBox);
        conversation_with_user->setObjectName(QString::fromUtf8("conversation_with_user"));
        conversation_with_user->setGeometry(QRect(110, 20, 541, 411));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush12(QColor(238, 238, 236, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush12);
        QBrush brush13(QColor(191, 64, 64, 0));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        conversation_with_user->setPalette(palette1);
        QFont font;
        font.setPointSize(17);
        conversation_with_user->setFont(font);
        conversation_with_user->setOverwriteMode(true);
        message_field = new QLineEdit(groupBox);
        message_field->setObjectName(QString::fromUtf8("message_field"));
        message_field->setGeometry(QRect(110, 430, 391, 71));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        QBrush brush14(QColor(250, 249, 248, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush14);
        message_field->setPalette(palette2);
        QFont font1;
        font1.setPointSize(14);
        message_field->setFont(font1);
        message_field->setFrame(false);
        send_button = new QPushButton(groupBox);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        send_button->setGeometry(QRect(500, 430, 61, 71));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("mail-send")));
        send_button->setIcon(icon);
        send_button->setIconSize(QSize(51, 112));
        send_button->setFlat(false);
        scrollbar_conversation = new QScrollBar(groupBox);
        scrollbar_conversation->setObjectName(QString::fromUtf8("scrollbar_conversation"));
        scrollbar_conversation->setGeometry(QRect(650, -70, 20, 621));
        QPalette palette3;
        QBrush brush15(QColor(92, 53, 102, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        scrollbar_conversation->setPalette(palette3);
        scrollbar_conversation->setOrientation(Qt::Vertical);
        reply_button = new QPushButton(groupBox);
        reply_button->setObjectName(QString::fromUtf8("reply_button"));
        reply_button->setGeometry(QRect(560, 430, 51, 71));
        QFont font2;
        font2.setPointSize(12);
        reply_button->setFont(font2);
        reply_number_text = new QTextEdit(groupBox);
        reply_number_text->setObjectName(QString::fromUtf8("reply_number_text"));
        reply_number_text->setGeometry(QRect(610, 430, 61, 71));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        reply_number_text->setPalette(palette4);
        QFont font3;
        font3.setPointSize(22);
        reply_number_text->setFont(font3);
        reply_number_text->setLayoutDirection(Qt::LeftToRight);
        reply_number_text->setLineWrapMode(QTextEdit::NoWrap);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 20, 628, 411));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/background.png")));
        users_list = new QListWidget(groupBox);
        users_list->setObjectName(QString::fromUtf8("users_list"));
        users_list->setGeometry(QRect(20, 20, 91, 411));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        users_list->setPalette(palette5);
        users_list->setFont(font1);
        users_list->setAcceptDrops(false);
        users_list->setAutoFillBackground(false);
        users_list->setAutoScroll(false);
        users_list->setTextElideMode(Qt::ElideMiddle);
        users_list->setFlow(QListView::TopToBottom);
        users_list->setLayoutMode(QListView::Batched);
        users_list->setSpacing(1);
        users_list->setViewMode(QListView::ListMode);
        users_list->setUniformItemSizes(true);
        users_list->setBatchSize(100);
        users_list->setWordWrap(false);
        logout_button = new QPushButton(groupBox);
        logout_button->setObjectName(QString::fromUtf8("logout_button"));
        logout_button->setGeometry(QRect(20, 430, 91, 71));
        logout_button->setFont(font2);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("dialog-password")));
        logout_button->setIcon(icon1);
        logout_button->setIconSize(QSize(57, 56));
        label->raise();
        message_field->raise();
        scrollbar_conversation->raise();
        send_button->raise();
        reply_button->raise();
        conversation_with_user->raise();
        users_list->raise();
        logout_button->raise();
        reply_number_text->raise();

        retranslateUi(conversations_page);

        QMetaObject::connectSlotsByName(conversations_page);
    } // setupUi

    void retranslateUi(QDialog *conversations_page)
    {
        conversations_page->setWindowTitle(QApplication::translate("conversations_page", "Conversation", nullptr));
        groupBox->setTitle(QString());
        conversation_with_user->setHtml(QApplication::translate("conversations_page", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:17pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        conversation_with_user->setPlaceholderText(QApplication::translate("conversations_page", "Select a user from the left to start talking.", nullptr));
        message_field->setText(QString());
        send_button->setText(QString());
        reply_button->setText(QApplication::translate("conversations_page", "Reply:", nullptr));
        reply_number_text->setHtml(QApplication::translate("conversations_page", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QString());
        logout_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class conversations_page: public Ui_conversations_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSATIONS_PAGE_H
