#include <QtWidgets>
#include <find_event_by_date_dialog.h>

//============================================================================================
//+++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА СОБЫТИЯ ПО ДАТЕ++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска события по дате
FindEventByDateDialog::FindEventByDateDialog(QWidget *parent)
    : QDialog(parent)
{
    FindDateEvent = "";

//Заголовок диалога поиска события по дате
    QLabel *HeadingLabel = new QLabel(tr("Ввод даты события для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска события по дате
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля даты события для поиска
    DateFindEventEdit = new QDateTimeEdit();
    DateFindEventEdit->setDate(QDate::currentDate());
    DateFindEventEdit->setDisplayFormat("dd-MM-yyyy");
    DateFindEventEdit->setCalendarPopup(true);

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(DateFindEventEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск события по дате"));
}

//Слот для диалогового окна поиска события по дате -
//нажатие на кнопку Найти
void FindEventByDateDialog::FindClicked()
{
    QDate date = DateFindEventEdit->date();
    FindDateEvent = date.toString("dd-MM-yy");
    hide();
}

//Функция для диалогового окна поиска события по дате
//Возврат назначенной даты события для поиска
QString FindEventByDateDialog::getFindDateEvent()
{
    return FindDateEvent;
}
