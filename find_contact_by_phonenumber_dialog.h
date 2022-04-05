#ifndef FIND_CONTACT_BY_PHONENUMBER_DIALOG_H
#define FIND_CONTACT_BY_PHONENUMBER_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QLineEdit;

//____________________________________________________________________________
// класс диалогового окна: поиск контакта по номеру телефона
class FindContactByPhoneNumberDialog : public QDialog
{
    Q_OBJECT

public:
    FindContactByPhoneNumberDialog (QWidget *parent = nullptr);
    QString getFindPhoneNumberContact();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего контакта
    QString FindPhoneNumberContact;
    QLineEdit *PhoneNumberFindContactEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________



#endif // FIND_CONTACT_BY_PHONENUMBER_DIALOG_H
