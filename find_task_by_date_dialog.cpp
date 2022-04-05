#include <QtWidgets>
#include <find_task_by_date_dialog.h>


//============================================================================================
//+++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА ДЕЛА ПО ДАТЕ++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска дела по дате
FindTaskByDateDialog::FindTaskByDateDialog(QWidget *parent)
    : QDialog(parent)
{
    FindDateTask = "";

//Заголовок диалога поиска дела по дате
    QLabel *HeadingLabel = new QLabel(tr("Ввод даты дела для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска дела по дате
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля даты дела для поиска
    DateFindTaskEdit = new QDateTimeEdit();
    DateFindTaskEdit->setDate(QDate::currentDate());
    DateFindTaskEdit->setDisplayFormat("dd-MM-yyyy");
    DateFindTaskEdit->setCalendarPopup(true);

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(DateFindTaskEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск дела по дате"));
}

//Слот для диалогового окна поиска дела по дате -
//нажатие на кнопку Найти
void FindTaskByDateDialog::FindClicked()
{
    QDate date = DateFindTaskEdit->date();
    FindDateTask = date.toString("dd-MM-yy");
    hide();
}

//Функция для диалогового окна поиска дела по дате
//Возврат назначенной даты дела для поиска
QString FindTaskByDateDialog::getFindDateTask()
{
    return FindDateTask;
}


