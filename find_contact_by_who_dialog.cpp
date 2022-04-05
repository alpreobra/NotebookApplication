#include <QtWidgets>
#include <find_contact_by_who_dialog.h>

//============================================================================================
//++++++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА КОНТАКТА ПО ЕГО РОЛИ+++++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска контакта по его роли
FindContactByWhoDialog::FindContactByWhoDialog(QWidget *parent)
    : QDialog(parent)
{
    FindWhoContact = "";

//Заголовок диалога поиска контакта по его роли
    QLabel *HeadingLabel = new QLabel(tr("Ввод роли контакта для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска контакта по его роли
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля роли контакта для его поиска
    WhoFindContactEdit = new QLineEdit();

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(WhoFindContactEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск контакта по его роли"));
}

//Слот для диалогового окна поиска контакта по его роли -
//нажатие на кнопку Найти
void FindContactByWhoDialog::FindClicked()
{
    QString str = WhoFindContactEdit->text();
    FindWhoContact = str;
    WhoFindContactEdit->clear();
    hide();
}

//Функция для диалогового окна поиска контакта по его роли
//Возврат назначенной роли контакта для поиска
QString FindContactByWhoDialog::getFindWhoContact()
{
    return FindWhoContact;
}
//============================================================================================
