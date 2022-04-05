#include <QtWidgets>
#include <add_contact_dialog.h>

//============================================================================================
//+++++++++++++++ДИАЛОГОВОЕ ОКНО ДОБАВЛЕНИЯ КОНТАКТА++++++++++++++++
//============================================================================================
//Конструктор диалогового окна добавления контакта
AddContactDialog::AddContactDialog(QWidget *parent)
    : QDialog(parent)
{
        FIOContact = "";
        EmailContact = "";
        PhoneNumberContact = "";
        WhoIsThatContact = "";

    //Заголовок окна добавления контакта
        QLabel *HeadingLabel = new QLabel(tr("Новый контакт"));
        HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
        QFont font("Arial",15);
        HeadingLabel->setFont(font);

    //Кнопки экрана добавления контакта
        OKButton = new QPushButton(tr("&Готово"));
        OKButton->setEnabled(false);
        AddButton = new QPushButton(tr("&Добавить контакт"));

    //Лейблы экрана добавления контакта
        QLabel *FIOLabel = new QLabel(tr("ФИО"));
        QLabel *EmailLabel = new QLabel(tr("*E-mail"));
        QLabel *PhoneNumberLabel = new QLabel(tr("Телефон"));
        QLabel *WhoIsThatLabel = new QLabel(tr("Кто это"));

    //Текстовые поля экрана добавления контакта
        FIOContactLine = new QLineEdit;
        EmailContactLine = new QLineEdit;
        PhoneNumberContactLine = new QLineEdit;
        WhoIsThatContactLine = new QLineEdit;

   //Соединяем сигналы и слоты
        connect(OKButton, SIGNAL(clicked()), this, SLOT(OKClicked()));
        connect(OKButton, SIGNAL(clicked()), this, SLOT(accept()));
        connect(AddButton, SIGNAL(clicked()), this, SLOT(AddClicked()));

    //Добавляем виджеты на layout'ы
        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
        mainLayout->addWidget(FIOLabel,1,0);
        mainLayout->addWidget(EmailLabel, 2, 0);
        mainLayout->addWidget(PhoneNumberLabel,3,0);
        mainLayout->addWidget(WhoIsThatLabel,4,0);
        mainLayout->addWidget(FIOContactLine,1,1);
        mainLayout->addWidget(EmailContactLine,2,1);
        mainLayout->addWidget(PhoneNumberContactLine,3,1);
        mainLayout->addWidget(WhoIsThatContactLine,4,1);
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(AddButton);
        buttonLayout->addWidget(OKButton);
        mainLayout->addLayout(buttonLayout,5,0,1,2);
        setLayout(mainLayout);
        setWindowTitle(tr("Добавление контакта"));
}

//Слот для диалогового окна добавления контакта -
//нажатие на кнопку Добавить
void AddContactDialog::AddClicked()
{
    QString FIO = FIOContactLine->text();
    QString Email = EmailContactLine->text();
    QString PhoneNumber = PhoneNumberContactLine->text();
    QString Who = WhoIsThatContactLine->text();

    //Проверка наличия пустых полей
    if (FIO == "" || PhoneNumber == "" || Who == ""){
        QMessageBox::information(this, tr("Пустое поле!"),
                     tr("Все поля без звездочки обязательны для заполнения!"));
                 return;
    } else {
        FIOContact = FIO;
        EmailContact = Email;
        PhoneNumberContact = PhoneNumber;
        WhoIsThatContact = Who;
        FIOContactLine->clear();
        EmailContactLine->clear();
        PhoneNumberContactLine->clear();
        WhoIsThatContactLine->clear();
        AddButton->setEnabled(false);
        OKButton->setEnabled(true);
    }
}

//Слот для диалогового окна добавления контакта -
//нажатие на кнопку Готово
void AddContactDialog::OKClicked()
{
    OKButton->setEnabled(false);
    AddButton->setEnabled(true);
    close();
}

//Функции для диалогового окна добавления контакта

//1) Возврат ФИО контакта
QString AddContactDialog::getFIOContact()
{
    return FIOContact;
}
//2) Возврат e-mail контакта
QString AddContactDialog::getEmailContact()
{
    return EmailContact;
}
//3) Возврат телефона контакта
QString AddContactDialog::getPhoneNumberContact()
{
    return PhoneNumberContact;
}
//4) Возврат роли контакта (информации о том, кем контакт является)
QString AddContactDialog::getWhoIsThatContact()
{
    return WhoIsThatContact;
}
