#ifndef FIND_CONTACT_BY_FIO_DIALOG_H
#define FIND_CONTACT_BY_FIO_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QLineEdit;

//____________________________________________________________________________
// класс диалогового окна: поиск контакта по ФИО
class FindContactByFioDialog : public QDialog
{
    Q_OBJECT

public:
    FindContactByFioDialog (QWidget *parent = nullptr);
    QString getFindFIOContact();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего контакта
    QString FindFIOContact;
    QLineEdit *FIOFindContactEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________

#endif // FIND_CONTACT_BY_FIO_DIALOG_H
