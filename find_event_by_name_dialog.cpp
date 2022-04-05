#include <QtWidgets>
#include <find_event_by_name_dialog.h>

//============================================================================================
//++++++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА СОБЫТИЯ ПО НАЗВАНИЮ+++++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска события по названию
FindEventByNameDialog::FindEventByNameDialog(QWidget *parent)
    : QDialog(parent)
{
    FindNameEvent = "";

//Заголовок диалога поиска события по названию
    QLabel *HeadingLabel = new QLabel(tr("Ввод названия события для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска события по названию
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля названия события для поиска
    NameFindEventEdit = new QLineEdit();

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(NameFindEventEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск события по названию"));
}

//Слот для диалогового окна поиска события по названию -
//нажатие на кнопку Найти
void FindEventByNameDialog::FindClicked()
{
    QString str = NameFindEventEdit->text();
    FindNameEvent = str;
    NameFindEventEdit->clear();
    hide();
}

//Функция для диалогового окна поиска события по дате
//Возврат назначенного названия события для поиска
QString FindEventByNameDialog::getFindNameEvent()
{
    return FindNameEvent;
}
//============================================================================================
