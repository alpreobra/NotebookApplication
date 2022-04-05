#ifndef ADD_CONTACT_DIALOG_H
#define ADD_CONTACT_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QLineEdit;

//____________________________________________________________________________
// класс диалогового окна: добавление контакта телефонной книги
class AddContactDialog : public QDialog
{
    Q_OBJECT

public:
    AddContactDialog (QWidget *parent = nullptr);
    QString getFIOContact();
    QString getEmailContact();
    QString getPhoneNumberContact();
    QString getWhoIsThatContact();

private slots:
    void OKClicked();
    void AddClicked();


private:
//Переменные для хранения характеристик текущего контакта
    QString FIOContact;
    QString EmailContact;
    QString PhoneNumberContact;
    QString WhoIsThatContact;

    QLineEdit *FIOContactLine;
    QLineEdit *EmailContactLine;
    QLineEdit *PhoneNumberContactLine;
    QLineEdit *WhoIsThatContactLine;
    QPushButton *OKButton;
    QPushButton *AddButton;

};
//____________________________________________________________________________

#endif // ADD_CONTACT_DIALOG_H
