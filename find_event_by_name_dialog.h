#ifndef FIND_EVENT_BY_NAME_DIALOG_H
#define FIND_EVENT_BY_NAME_DIALOG_H

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
// класс диалогового окна: поиск события по названию
class FindEventByNameDialog : public QDialog
{
    Q_OBJECT

public:
    FindEventByNameDialog (QWidget *parent = nullptr);
    QString getFindNameEvent();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего события
    QString FindNameEvent;
    QLineEdit *NameFindEventEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________

#endif // FIND_EVENT_BY_NAME_DIALOG_H
