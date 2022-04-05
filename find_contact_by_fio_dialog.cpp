#include <QtWidgets>
#include <find_contact_by_fio_dialog.h>

//============================================================================================
//++++++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА КОНТАКТА ПО ФИО+++++++++++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска контакта по ФИО
FindContactByFioDialog::FindContactByFioDialog(QWidget *parent)
    : QDialog(parent)
{
    FindFIOContact = "";

//Заголовок диалога поиска контакта по ФИО
    QLabel *HeadingLabel = new QLabel(tr("Ввод ФИО контакта для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска контакта по ФИО
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля ФИО контакта для поиска
    FIOFindContactEdit = new QLineEdit();

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(FIOFindContactEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск контакта по ФИО"));
}

//Слот для диалогового окна поиска контакта по ФИО -
//нажатие на кнопку Найти
void FindContactByFioDialog::FindClicked()
{
    QString str = FIOFindContactEdit->text();
    FindFIOContact = str;
    FIOFindContactEdit->clear();
    hide();
}

//Функция для диалогового окна поиска контакта по ФИО
//Возврат ФИО контакта для поиска
QString FindContactByFioDialog::getFindFIOContact()
{
    return FindFIOContact;
}
//============================================================================================
