#ifndef FIND_CONTACT_BY_WHO_DIALOG_H
#define FIND_CONTACT_BY_WHO_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QLineEdit;
class QDateTimeEdit;
//____________________________________________________________________________
// класс диалогового окна: поиск контакта по роли
class FindContactByWhoDialog : public QDialog
{
    Q_OBJECT

public:
    FindContactByWhoDialog (QWidget *parent = nullptr);
    QString getFindWhoContact();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего контакта
    QString FindWhoContact;
    QLineEdit *WhoFindContactEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________


#endif // FIND_CONTACT_BY_WHO_DIALOG_H
