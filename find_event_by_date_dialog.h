#ifndef FIND_EVENT_BY_DATE_DIALOG_H
#define FIND_EVENT_BY_DATE_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QDateTimeEdit;

//____________________________________________________________________________
// класс диалогового окна: поиск события по дате
class FindEventByDateDialog : public QDialog
{
    Q_OBJECT

public:
    FindEventByDateDialog (QWidget *parent = nullptr);
    QString getFindDateEvent();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего события
    QString FindDateEvent;
    QDateTimeEdit *DateFindEventEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________

#endif // FIND_EVENT_BY_DATE_DIALOG_H
