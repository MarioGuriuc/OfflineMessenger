/********************************************************************************
** Form generated from reading UI file 'login_or_register_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_OR_REGISTER_PAGE_H
#define UI_LOGIN_OR_REGISTER_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_or_register_page
{
public:
    QGroupBox *groupBox;
    QPushButton *login_button;
    QLabel *username;
    QLabel *password;
    QLineEdit *username_text;
    QLineEdit *password_text;
    QPushButton *back_button;
    QLabel *label;
    QPushButton *register_button;

    void setupUi(QDialog *login_or_register_page)
    {
        if (login_or_register_page->objectName().isEmpty())
            login_or_register_page->setObjectName(QString::fromUtf8("login_or_register_page"));
        login_or_register_page->resize(640, 480);
        login_or_register_page->setMinimumSize(QSize(640, 480));
        login_or_register_page->setMaximumSize(QSize(640, 480));
        QPalette palette;
        QBrush brush(QColor(173, 127, 168, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        login_or_register_page->setPalette(palette);
        login_or_register_page->setCursor(QCursor(Qt::CrossCursor));
        groupBox = new QGroupBox(login_or_register_page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 640, 480));
        groupBox->setMaximumSize(QSize(640, 480));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush2(QColor(255, 192, 248, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(214, 159, 208, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(86, 63, 84, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(115, 85, 112, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush7(QColor(214, 191, 211, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush10(QColor(86, 63, 84, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        QBrush brush11(QColor(225, 165, 218, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush11);
        groupBox->setPalette(palette1);
        groupBox->setFlat(false);
        login_button = new QPushButton(groupBox);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(227, 280, 80, 24));
        login_button->setMaximumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(12);
        login_button->setFont(font);
        login_button->setCursor(QCursor(Qt::CrossCursor));
        login_button->setAutoFillBackground(false);
        login_button->setCheckable(false);
        login_button->setAutoDefault(true);
        login_button->setFlat(true);
        username = new QLabel(groupBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(190, 160, 91, 31));
        username->setMaximumSize(QSize(640, 480));
        password = new QLabel(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(190, 220, 91, 31));
        password->setMaximumSize(QSize(640, 480));
        username_text = new QLineEdit(groupBox);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setGeometry(QRect(270, 160, 113, 31));
        username_text->setMaximumSize(QSize(640, 480));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        username_text->setPalette(palette2);
        username_text->setAutoFillBackground(false);
        username_text->setClearButtonEnabled(false);
        password_text = new QLineEdit(groupBox);
        password_text->setObjectName(QString::fromUtf8("password_text"));
        password_text->setGeometry(QRect(270, 220, 113, 31));
        password_text->setMaximumSize(QSize(640, 480));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        password_text->setPalette(palette3);
        password_text->setEchoMode(QLineEdit::Password);
        back_button = new QPushButton(groupBox);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(30, 30, 80, 21));
        back_button->setMaximumSize(QSize(640, 480));
        back_button->setCursor(QCursor(Qt::CrossCursor));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 640, 480));
        label->setMaximumSize(QSize(640, 480));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/background.png")));
        register_button = new QPushButton(groupBox);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setEnabled(true);
        register_button->setGeometry(QRect(317, 278, 101, 31));
        register_button->setMaximumSize(QSize(640, 480));
        register_button->setFont(font);
        register_button->setCursor(QCursor(Qt::CrossCursor));
#ifndef QT_NO_TOOLTIP
        register_button->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        register_button->setStatusTip(QString::fromUtf8(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        register_button->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
        register_button->setFlat(true);
        label->raise();
        login_button->raise();
        username->raise();
        password->raise();
        username_text->raise();
        password_text->raise();
        back_button->raise();
        register_button->raise();

        retranslateUi(login_or_register_page);

        login_button->setDefault(true);
        register_button->setDefault(true);


        QMetaObject::connectSlotsByName(login_or_register_page);
    } // setupUi

    void retranslateUi(QDialog *login_or_register_page)
    {
        login_or_register_page->setWindowTitle(QApplication::translate("login_or_register_page", "Login or Register", nullptr));
        groupBox->setTitle(QString());
        login_button->setText(QApplication::translate("login_or_register_page", "Login", nullptr));
        username->setText(QApplication::translate("login_or_register_page", "Username:", nullptr));
        password->setText(QApplication::translate("login_or_register_page", "Password:", nullptr));
        back_button->setText(QApplication::translate("login_or_register_page", "Back", nullptr));
        label->setText(QString());
        register_button->setText(QApplication::translate("login_or_register_page", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_or_register_page: public Ui_login_or_register_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_OR_REGISTER_PAGE_H
