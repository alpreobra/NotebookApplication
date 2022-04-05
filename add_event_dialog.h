#ifndef ADD_EVENT_DIALOG_H
#define ADD_EVENT_DIALOG_H

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
// класс диалогового окна: добавление события
class AddEventDialog : public QDialog
{
    Q_OBJECT

public:
    AddEventDialog (QWidget *parent = nullptr);
    QString getDateEvent();
    QString getNameEvent();
    QString getCommentEvent();

private slots:
    void SelectedDateChanged();
    void OKClicked();
    void AddClicked();


private:
//Переменные для хранения характеристик текущего события
    QString DateEvent;
    QString NameEvent;
    QString CommentEvent;

    QLineEdit *DateEventLine;
    QLineEdit *NameEventLine;
    QLineEdit *CommentEventLine;
    QPushButton *OKButton;
    QPushButton *AddButton;
    QCalendarWidget *Calendar;
};
//____________________________________________________________________________

#endif // ADD_EVENT_DIALOG_H
