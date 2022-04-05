#ifndef FIND_TASK_BY_DATE_DIALOG_H
#define FIND_TASK_BY_DATE_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QDateTimeEdit;

//____________________________________________________________________________
// класс диалогового окна: поиск дела по дате
class FindTaskByDateDialog : public QDialog
{
    Q_OBJECT

public:
    FindTaskByDateDialog (QWidget *parent = nullptr);
    QString getFindDateTask();

private slots:
    void FindClicked();

private:
//Переменные для хранения характеристик поиска текущего дела
    QString FindDateTask;
    QDateTimeEdit *DateFindTaskEdit;
    QPushButton *FindButton;
};
//____________________________________________________________________________


#endif // FIND_TASK_BY_DATE_DIALOG_H
