#ifndef ADD_TASK_DIALOG_H
#define ADD_TASK_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>

class QPushButton;
class QLabel;
class QCalendarWidget;
class QLineEdit;


//____________________________________________________________________________
// класс диалогового окна: добавление дела
class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    AddTaskDialog (QWidget *parent = nullptr);
    QString getDateTask();
    QString getNameTask();
    QString getCommentTask();

private slots:
    void SelectedDateChanged();
    void OKClicked();
    void AddClicked();


private:
//Переменные для хранения характеристик текущего дела
    QString DateTask;
    QString NameTask;
    QString CommentTask;

    QLineEdit *DateTaskLine;
    QLineEdit *NameTaskLine;
    QLineEdit *CommentTaskLine;
    QPushButton *OKButton;
    QPushButton *AddButton;
    QCalendarWidget *Calendar;
};
//____________________________________________________________________________

#endif // ADD_TASK_DIALOG_H
