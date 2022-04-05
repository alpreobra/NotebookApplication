#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <add_contact_dialog.h>
#include <find_contact_by_fio_dialog.h>
#include <find_contact_by_phonenumber_dialog.h>
#include <find_contact_by_who_dialog.h>
#include <add_event_dialog.h>
#include <find_event_by_date_dialog.h>
#include <find_event_by_name_dialog.h>
#include <add_task_dialog.h>
#include <find_task_by_date_dialog.h>

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRecord>

class QGroupBox;
class QPushButton;
class QLabel;
class QCalendarWidget;
class QLineEdit;
class QTextEdit;
class QDateTimeEdit;

//___________________________________________________________________________
// класс главного окна записной книжки, куда помещаются все остальные виджеты
class Notebook : public QWidget
{
    Q_OBJECT

public:
    Notebook (QWidget *parent = nullptr);

private:
    QSqlDatabase db;
//Запросы
    QSqlQuery *query_cr_pbTable;
    QSqlQuery *query_cr_ebTable;
    QSqlQuery *query_cr_tbTable;
//Табличные модели
    QSqlTableModel *model_phonebook;
    QSqlTableModel *model_eventbook;
    QSqlTableModel *model_todobook;

    QTableView *phoneView;
    QTableView *eventView;
    QTableView *todoView;

//Группбоксы
    QGroupBox *PhoneBookGroupBox;
    QGroupBox *EventBookGroupBox;
    QGroupBox *TodoBookGroupBox;

//Кнопки телефонной книги
    QPushButton *AddContactBtn;
    QPushButton *DeleteContactBtn;
    QPushButton *FindContactByFioBtn;
    QPushButton *FindContactByPhonenumberBtn;
    QPushButton *FindContactByWhoBtn;
    QPushButton *CancelPhoneFilterBtn;

//Кнопки журнала событий
    QPushButton *AddEventBtn;
    QPushButton *DeleteEventBtn;
    QPushButton *FindEventByDateBtn;
    QPushButton *FindEventByNameBtn;
    QPushButton *CancelEventFilterBtn;

//Кнопки журнала дел
    QPushButton *AddTaskBtn;
    QPushButton *DeleteTaskBtn;
    QPushButton *FindTaskByDateBtn;
    QPushButton *CancelTaskFilterBtn;

//Диалоговые окна

    //Диалоговые окна работы Телефонной книги
    AddContactDialog *ContactDialog;
    FindContactByFioDialog *FindConFIODialog;
    FindContactByPhoneNumberDialog *FindConPNDialog;
    FindContactByWhoDialog *FindConWhoDialog;

    //Диалоговые окна работы Журнала событий
    AddEventDialog *EventDialog;
    FindEventByDateDialog *FindEvDateDialog;
    FindEventByNameDialog *FindEvNameDialog;

    //Диалоговые окна работы Журнала дел
    AddTaskDialog *TaskDialog;
    FindTaskByDateDialog *FindTsDateDialog;

    int row;

private slots:
    //Слоты для телефонной книги
    void AddContact();
    void DeleteContact();
    void FindContactByFio();
    void FindContactByPhonenumber();
    void FindContactByWho();
    void CancelPhoneFilter();

    //Слоты для журнала событий
    void AddEvent();
    void DeleteEvent();
    void FindEventByDate();
    void FindEventByName();
    void CancelEventFilter();

    //Слоты для журнала дел
    void AddTask();
    void DeleteTask();
    void FindTaskByDate();
    void CancelTaskFilter();


};
//___________________________________________________________________________

#endif // NOTEBOOK_H
