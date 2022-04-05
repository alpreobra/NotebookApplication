#include <QtWidgets>
#include <find_contact_by_phonenumber_dialog.h>


//============================================================================================
//++++++++++++++++++ДИАЛОГОВОЕ ОКНО ПОИСКА КОНТАКТА ПО НОМЕРУ ТЕЛЕФОНА+++++++++++++++++++++++
//============================================================================================

//Конструктор диалогового окна поиска контакта по номеру телефона
FindContactByPhoneNumberDialog::FindContactByPhoneNumberDialog(QWidget *parent)
    : QDialog(parent)
{
    FindPhoneNumberContact = "";

//Заголовок диалога поиска контакта по номеру телефона
    QLabel *HeadingLabel = new QLabel(tr("Ввод телефона контакта для поиска"));
    HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
    QFont font("Arial",15);
    HeadingLabel->setFont(font);

//Кнопка диалога поиска контакта по номеру телефона
    FindButton = new QPushButton(tr("&Найти"));

//Настройка поля телефона контакта для поиска
    PhoneNumberFindContactEdit = new QLineEdit();

//Соединяем сигналы и слоты
    connect(FindButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(FindButton, SIGNAL(clicked()), this, SLOT(FindClicked()));

//Добавляем виджеты на layout'ы
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
    mainLayout->addWidget(PhoneNumberFindContactEdit,1,0);
    mainLayout->addWidget(FindButton,1,1);
    setLayout(mainLayout);
    setWindowTitle(tr("Поиск контакта по номеру телефона"));
}

//Слот для диалогового окна поиска контакта по номеру телефона -
//нажатие на кнопку Найти
void FindContactByPhoneNumberDialog::FindClicked()
{
    FindPhoneNumberContact = PhoneNumberFindContactEdit->text();
    PhoneNumberFindContactEdit->clear();
    hide();
}

//Функция для диалогового окна поиска контакта по номеру телефона
//Возврат телефона контакта для поиска
QString FindContactByPhoneNumberDialog::getFindPhoneNumberContact()
{
    return FindPhoneNumberContact;
}
//============================================================================================
