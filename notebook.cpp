#include <QtWidgets>
#include "notebook.h"

Notebook::Notebook(QWidget *parent)
    : QWidget(parent)
{

//Создание группбоксов
    PhoneBookGroupBox = new QGroupBox(tr("Телефонная книга"));
    PhoneBookGroupBox->setAlignment(Qt::AlignHCenter);
    PhoneBookGroupBox->setStyleSheet("QGroupBox { background-color: cyan; font-size: 18px; font-weight: bold; }");

    EventBookGroupBox = new QGroupBox(tr("Журнал событий"));
    EventBookGroupBox->setAlignment(Qt::AlignHCenter);
    EventBookGroupBox->setStyleSheet("QGroupBox { background-color: lightgreen; font-size: 18px; font-weight: bold; }");

    TodoBookGroupBox = new QGroupBox(tr("Журнал дел"));
    TodoBookGroupBox->setAlignment(Qt::AlignHCenter);
    TodoBookGroupBox->setStyleSheet("QGroupBox { background-color: yellow; font-size: 18px; font-weight: bold; }");

//Создание базы данных Записной книжки
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./NotebookDB.db");

//Проверка подключения к БД
    if (db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug(" close");
    }

//Создание таблиц ЗАПИСНОЙ КНИЖКИ и вывод их на экран

    //Таблица телефонной книги
    query_cr_pbTable = new QSqlQuery(db);
    query_cr_pbTable->exec("CREATE TABLE phonebook(FIO TEXT, Email TEXT, PhoneNumber TEXT, WhoIsThat TEXT); ");
    model_phonebook = new QSqlTableModel(this,db);
    model_phonebook->setTable("phonebook");
    model_phonebook->select();
    model_phonebook->setEditStrategy(QSqlTableModel::OnManualSubmit);
    phoneView = new QTableView;
    phoneView->setModel(model_phonebook);
    //Закрываем возможность редактирования для пользователя
    phoneView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Растягиваем столбцы на ширину таблицы
    phoneView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Таблица журнала событий
    query_cr_ebTable = new QSqlQuery(db);
    query_cr_ebTable->exec("CREATE TABLE eventbook(DateOfEvent TEXT, EventTitle TEXT, Comments TEXT); ");
    model_eventbook = new QSqlTableModel(this,db);
    model_eventbook->setTable("eventbook");
    model_eventbook->select();
    model_eventbook->setEditStrategy(QSqlTableModel::OnManualSubmit);
    eventView = new QTableView;
    eventView->setModel(model_eventbook);
    eventView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    eventView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Таблица журнала дел
    query_cr_tbTable = new QSqlQuery(db);
    query_cr_tbTable->exec("CREATE TABLE todobook(Date TEXT, Task TEXT, Comments TEXT); ");
    model_todobook = new QSqlTableModel(this,db);
    model_todobook->setTable("todoBook");
    model_todobook->select();
    model_todobook->setEditStrategy(QSqlTableModel::OnManualSubmit);
    todoView = new QTableView;
    todoView->setModel(model_todobook);
    todoView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    todoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//==========================================================================================================
        //ТЕЛЕФОННАЯ КНИГА
//==========================================================================================================
//Создание кнопок телефонной книги
    AddContactBtn = new QPushButton(tr("&Добавить контакт"));
    DeleteContactBtn = new QPushButton(tr("&Удалить контакт"));
    FindContactByFioBtn = new QPushButton(tr("&Найти по ФИО"));
    FindContactByPhonenumberBtn = new QPushButton(tr("&Найти по телефону"));
    FindContactByWhoBtn = new QPushButton(tr("&Найти по роли"));
    CancelPhoneFilterBtn = new QPushButton(tr("&Отменить фильтры"));

//Диалоговые окна телефонной книги
    ContactDialog = new AddContactDialog;
    FindConFIODialog = new FindContactByFioDialog;
    FindConPNDialog = new FindContactByPhoneNumberDialog;
    FindConWhoDialog = new FindContactByWhoDialog;

//Создание соединений слотов и сигналов для телефонной книги
    connect(AddContactBtn, SIGNAL(clicked()), this, SLOT(AddContact()));
    connect(DeleteContactBtn, SIGNAL(clicked()), this, SLOT(DeleteContact()));
    connect(FindContactByFioBtn, SIGNAL(clicked()), this, SLOT(FindContactByFio()));
    connect(FindContactByPhonenumberBtn, SIGNAL(clicked()), this, SLOT(FindContactByPhonenumber()));
    connect(FindContactByWhoBtn, SIGNAL(clicked()), this, SLOT(FindContactByWho()));
    connect(CancelPhoneFilterBtn, SIGNAL(clicked()), this, SLOT(CancelPhoneFilter()));

//Размещение виджетов телефонной книги на layout'е
    QGridLayout *PhoneBookGroupBoxLayout = new QGridLayout;
    PhoneBookGroupBoxLayout->addWidget(AddContactBtn, 0, 0);
    PhoneBookGroupBoxLayout->addWidget(DeleteContactBtn, 0, 1);
    PhoneBookGroupBoxLayout->addWidget(FindContactByFioBtn, 0, 2);
    PhoneBookGroupBoxLayout->addWidget(FindContactByPhonenumberBtn, 0, 3);
    PhoneBookGroupBoxLayout->addWidget(FindContactByWhoBtn, 0, 4);
    PhoneBookGroupBoxLayout->addWidget(CancelPhoneFilterBtn, 0, 5);
    PhoneBookGroupBoxLayout->addWidget(phoneView,1,0,1,6);
    PhoneBookGroupBox->setLayout(PhoneBookGroupBoxLayout);

//==========================================================================================================
     //ЖУРНАЛ СОБЫТИЙ
//==========================================================================================================
//Создание кнопок журнала событий
    AddEventBtn = new QPushButton(tr("&Добавить событие"));
    DeleteEventBtn = new QPushButton(tr("&Удалить событие"));
    FindEventByDateBtn = new QPushButton(tr("&Поиск по дате"));
    FindEventByNameBtn = new QPushButton(tr("&Поиск по названию"));
    CancelEventFilterBtn = new QPushButton(tr("&Отменить фильтры"));

//Диалоговые окна журнала событий
    EventDialog = new AddEventDialog;
    FindEvDateDialog = new FindEventByDateDialog;
    FindEvNameDialog = new FindEventByNameDialog;

//Создание соединений слотов и сигналов для журнала событий
    connect(AddEventBtn, SIGNAL(clicked()), this, SLOT(AddEvent()));
    connect(DeleteEventBtn, SIGNAL(clicked()), this, SLOT(DeleteEvent()));
    connect(FindEventByDateBtn, SIGNAL(clicked()), this, SLOT(FindEventByDate()));
    connect(FindEventByNameBtn, SIGNAL(clicked()), this, SLOT(FindEventByName()));
    connect(CancelEventFilterBtn, SIGNAL(clicked()), this, SLOT(CancelEventFilter()));

//Размещение виджетов журнала событий на layout'е
    QGridLayout *EventBookGroupBoxLayout = new QGridLayout;
    EventBookGroupBoxLayout->addWidget(AddEventBtn, 0, 0);
    EventBookGroupBoxLayout->addWidget(DeleteEventBtn, 0, 1);
    EventBookGroupBoxLayout->addWidget(FindEventByDateBtn, 0, 2);
    EventBookGroupBoxLayout->addWidget(FindEventByNameBtn, 0, 3);
    EventBookGroupBoxLayout->addWidget(CancelEventFilterBtn, 0, 4);
    EventBookGroupBoxLayout->addWidget(eventView, 1,0,1,5);
    EventBookGroupBox->setLayout(EventBookGroupBoxLayout);

//==========================================================================================================
    //ЖУРНАЛ ДЕЛ
//==========================================================================================================
//Создание кнопок журнала дел
    AddTaskBtn = new QPushButton(tr("&Добавить дело"));
    DeleteTaskBtn = new QPushButton(tr("&Удалить дело"));
    FindTaskByDateBtn = new QPushButton(tr("&Поиск по дате"));
    CancelTaskFilterBtn = new QPushButton(tr("&Отменить фильтр"));

//Диалоговые окна журнала дел
    TaskDialog = new AddTaskDialog;
    FindTsDateDialog = new FindTaskByDateDialog;

//Создание соединений слотов и сигналов для журнала дел
    connect(AddTaskBtn, SIGNAL(clicked()), this, SLOT(AddTask()));
    connect(DeleteTaskBtn, SIGNAL(clicked()), this, SLOT(DeleteTask()));
    connect(FindTaskByDateBtn, SIGNAL(clicked()), this, SLOT(FindTaskByDate()));
    connect(CancelTaskFilterBtn, SIGNAL(clicked()), this, SLOT(CancelTaskFilter()));

//Размещение виджетов журнала дел на layout'е
    QGridLayout *TodoBookGroupBoxLayout = new QGridLayout;
    TodoBookGroupBoxLayout->addWidget(AddTaskBtn, 0, 0);
    TodoBookGroupBoxLayout->addWidget(DeleteTaskBtn, 0, 1);
    TodoBookGroupBoxLayout->addWidget(FindTaskByDateBtn, 0, 2);
    TodoBookGroupBoxLayout->addWidget(CancelTaskFilterBtn, 0, 3);
    TodoBookGroupBoxLayout->addWidget(todoView, 1,0,1,4);
    TodoBookGroupBox->setLayout(TodoBookGroupBoxLayout);


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Добавление всех группбоксов с виджетами на главный layout
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(PhoneBookGroupBox,0,0,1,2);
    mainLayout->addWidget(EventBookGroupBox,1,0);
    mainLayout->addWidget(TodoBookGroupBox,1,1);

    setLayout(mainLayout);
    setWindowTitle(tr("Добро пожаловать в записную книжку!"));

}

//============================================================================================
//++++++++++++++++СЛОТЫ ТЕЛЕФОННОЙ КНИГИ+++++++++++++++++
//============================================================================================

//1) Слот добавления нового контакта
void Notebook::AddContact()
{
    ContactDialog->show();
    if (ContactDialog->exec() == QDialog::Accepted) {
        int lastRow = model_phonebook->rowCount();
        QString FIO = ContactDialog->getFIOContact();
        QString Email = ContactDialog->getEmailContact();
        QString Phone = ContactDialog->getPhoneNumberContact();
        QString Who = ContactDialog->getWhoIsThatContact();
        QSqlRecord record1 = model_phonebook->record();
        record1.setValue(0, FIO);
        record1.setValue(1, Email);
        record1.setValue(2, Phone);
        record1.setValue(3, Who);
        //Проверка на наличие дубликатов
        //Дубликатами в телефонной книге считаются
        // записи с одинаковыми значениями всех полей
        int S = 0;
        if(lastRow == 0){
                //Добавление записи в таблицу, так как она пустая
                //и нет необходимости в проверке наличия в ней дубликатов
                model_phonebook->insertRecord(lastRow,record1);
                model_phonebook->submitAll();
            } else {
                QSqlRecord record2;
                for (int row = 0;row<lastRow;row++)
                    {
                        record2=model_phonebook->record(row);
                        if (record1.value(0)==record2.value(0) &&
                                record1.value(1)==record2.value(1) &&
                                record1.value(2)==record2.value(2) &&
                                record1.value(3)==record2.value(3))
                                {
                                    QMessageBox::information(this, tr("Отказ в записи!"),
                                              tr("Упс!Такая запись в телефонной книге уже существует!"));
                                    break;
                                }
                         S = S+1;
                    }

                 if (S==lastRow){
                     //Добавление записи в таблицу,
                     //так как цикл прошел до конца без прерывания
                     model_phonebook->insertRecord(lastRow,record1);
                     model_phonebook->submitAll();
                    }
            }
    }
}

//2) Слот удаления выбранного контакта
void Notebook::DeleteContact()
{
    row = phoneView->selectionModel()->currentIndex().row();
    model_phonebook->removeRow(row);
    model_phonebook->submitAll();
}

//3) Слот поиска контакта по ФИО
void Notebook::FindContactByFio()
{
    FindConFIODialog->show();
    if (FindConFIODialog->exec() == QDialog::Accepted) {
        int lastRow = model_phonebook->rowCount();
        QString str = FindConFIODialog->getFindFIOContact();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_phonebook->record(row);
                            if (record1.value(0)!=str){
                                phoneView->setRowHidden(row,true);
                            }
                      }
    }
}

//4) Слот поиска контакта по номеру телефона
void Notebook::FindContactByPhonenumber()
{
    FindConPNDialog->show();
    if (FindConPNDialog->exec() == QDialog::Accepted) {
        int lastRow = model_phonebook->rowCount();
        QString str = FindConPNDialog->getFindPhoneNumberContact();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_phonebook->record(row);
                            if (record1.value(2)!=str){
                                phoneView->setRowHidden(row,true);
                            }
                      }
    }
}

//5) Слот поиска контакта по его роли в телефонной книге -
//то есть информации о том, кем является контакт
void Notebook::FindContactByWho()
{
    FindConWhoDialog->show();
    if (FindConWhoDialog->exec() == QDialog::Accepted) {
        int lastRow = model_phonebook->rowCount();
        QString str = FindConWhoDialog->getFindWhoContact();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_phonebook->record(row);
                            if (record1.value(3)!=str){
                                phoneView->setRowHidden(row,true);
                            }
                      }
    }
}

//6) Слот отмены действия фильтров телефонной книги
void Notebook::CancelPhoneFilter()
{
    int lastRow = model_phonebook->rowCount();
    for (int row = 0;row<lastRow;row++)
        {
            phoneView->setRowHidden(row,false);
        }
}

//============================================================================================
//++++++++++++++++СЛОТЫ ЖУРНАЛА СОБЫТИЙ+++++++++++++++++
//============================================================================================

//1) Слот добавления нового события
void Notebook::AddEvent()
{
    EventDialog->show();
    if (EventDialog->exec() == QDialog::Accepted) {
        int lastRow = model_eventbook->rowCount();
        QString Data = EventDialog->getDateEvent();
        QString Name = EventDialog->getNameEvent();
        QString Comment = EventDialog->getCommentEvent();
        QSqlRecord record1 = model_eventbook->record();
        record1.setValue(0, Data);
        record1.setValue(1, Name);
        record1.setValue(2, Comment);
        //Проверка на наличие дубликатов
        //Дубликатами в журнале событий считаются
        // записи с одинаковыми значениями всех полей
        int S = 0;
        if(lastRow == 0){
                //Добавление записи в таблицу, так как она пустая
                //и нет необходимости в проверке наличия в ней дубликатов
                model_eventbook->insertRecord(lastRow,record1);
                model_eventbook->submitAll();
            } else {
                QSqlRecord record2;
                for (int row = 0;row<lastRow;row++)
                    {
                        record2=model_eventbook->record(row);
                        if (record1.value(0)==record2.value(0) &&
                              record1.value(1)==record2.value(1) &&
                              record1.value(2)==record2.value(2))
                                {
                                    QMessageBox::information(this, tr("Отказ в записи!"),
                                              tr("Упс!Такая запись уже существует!"));
                                    break;
                                }
                         S = S+1;
                    }

                 if (S==lastRow){
                     //Добавление записи в таблицу,
                     //так как цикл прошел до конца без прерывания
                     model_eventbook->insertRecord(lastRow,record1);
                     model_eventbook->submitAll();
                    }
            }
    }
}

//2) Слот удаления выбранного события
void Notebook::DeleteEvent()
{
    row = eventView->selectionModel()->currentIndex().row();
    model_eventbook->removeRow(row);
    model_eventbook->submitAll();
}

//3) Слот поиска события по дате
void Notebook::FindEventByDate()
{
    FindEvDateDialog->show();
    if (FindEvDateDialog->exec() == QDialog::Accepted) {
        int lastRow = model_eventbook->rowCount();
        QString str = FindEvDateDialog->getFindDateEvent();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_eventbook->record(row);
                            if (record1.value(0)!=str){
                                eventView->setRowHidden(row,true);
                            }
                      }
    }
}

//4) Слот поиска события по названию
void Notebook::FindEventByName()
{
    FindEvNameDialog->show();
    if (FindEvNameDialog->exec() == QDialog::Accepted) {
        int lastRow = model_eventbook->rowCount();
        QString str = FindEvNameDialog->getFindNameEvent();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_eventbook->record(row);
                            if (record1.value(1)!=str){
                                eventView->setRowHidden(row,true);
                            }
                      }
    }
}

//5) Слот отмены действия фильтров журнала событий
void Notebook::CancelEventFilter()
{
    int lastRow = model_eventbook->rowCount();
    for (int row = 0;row<lastRow;row++)
        {
            eventView->setRowHidden(row,false);
        }
}

//============================================================================================
//++++++++++++++++СЛОТЫ ЖУРНАЛА ДЕЛ+++++++++++++++++
//============================================================================================
//1) Слот добавления нового дела
void Notebook::AddTask()
{
    TaskDialog->show();
    if (TaskDialog->exec() == QDialog::Accepted) {
        int lastRow = model_todobook->rowCount();
        QString Data = TaskDialog->getDateTask();
        QString Name = TaskDialog->getNameTask();
        QString Comment = TaskDialog->getCommentTask();
        QSqlRecord record1 = model_todobook->record();
        record1.setValue(0, Data);
        record1.setValue(1, Name);
        record1.setValue(2, Comment);
        //Проверка на наличие дубликатов
        //Дубликатами в журнале дел считаются
        // записи с одинаковыми значениями всех полей
        int S = 0;
        if(lastRow == 0){
                //Добавление записи в таблицу, так как она пустая
                //и нет необходимости в проверке наличия в ней дубликатов
                model_todobook->insertRecord(lastRow,record1);
                model_todobook->submitAll();
            } else {
                QSqlRecord record2;
                for (int row = 0;row<lastRow;row++)
                    {
                        record2=model_todobook->record(row);
                        if (record1.value(0)==record2.value(0) &&
                              record1.value(1)==record2.value(1) &&
                              record1.value(2)==record2.value(2))
                                {
                                    QMessageBox::information(this, tr("Отказ в записи!"),
                                              tr("Упс!Такое дело уже существует!"));
                                    break;
                                }
                         S = S+1;
                    }

                 if (S==lastRow){
                     //Добавление записи в таблицу,
                     //так как цикл прошел до конца без прерывания
                     model_todobook->insertRecord(lastRow,record1);
                     model_todobook->submitAll();
                    }
            }
    }
}

//2) Слот удаления выбранного дела
void Notebook::DeleteTask()
{
    row = todoView->selectionModel()->currentIndex().row();
    model_todobook->removeRow(row);
    model_todobook->submitAll();
}

//3) Слот поиска дела по дате
void Notebook::FindTaskByDate()
{
    FindTsDateDialog->show();
    if (FindTsDateDialog->exec() == QDialog::Accepted) {
        int lastRow = model_todobook->rowCount();
        QString str = FindTsDateDialog->getFindDateTask();
        for (int row = 0;row<lastRow;row++)
                     {
                            QSqlRecord record1=model_todobook->record(row);
                            if (record1.value(0)!=str){
                                todoView->setRowHidden(row,true);
                            }
                      }
    }
}

//4) Слот отмены действия фильтров журнала дел
void Notebook::CancelTaskFilter()
{
    int lastRow = model_todobook->rowCount();
    for (int row = 0;row<lastRow;row++)
        {
            todoView->setRowHidden(row,false);
        }
}





