#include <QtWidgets>
#include <add_event_dialog.h>

//============================================================================================
//+++++++++++++++ДИАЛОГОВОЕ ОКНО ДОБАВЛЕНИЯ СОБЫТИЯ++++++++++++++++
//============================================================================================
//Конструктор диалогового окна добавления события
AddEventDialog::AddEventDialog(QWidget *parent)
    : QDialog(parent)
{
        DateEvent = "";
        NameEvent = "";
        CommentEvent = "";

    //Заголовок окна добавления события
        QLabel *HeadingLabel = new QLabel(tr("Новое событие"));
        HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
        QFont font("Arial",15);
        HeadingLabel->setFont(font);

    //Кнопки экрана добавления события
        OKButton = new QPushButton(tr("&Готово"));
        OKButton->setEnabled(false);
        AddButton = new QPushButton(tr("&Добавить событие"));

    //Лейблы экрана добавления события
        QLabel *DataLabel = new QLabel(tr("Дата события"));
        QLabel *EventLabel = new QLabel(tr("Что за событие"));
        QLabel *CommentLabel = new QLabel(tr("Комментарий"));

    //Текстовые поля экрана добавления события
        DateEventLine = new QLineEdit;
        DateEventLine->setEnabled(false);
        NameEventLine = new QLineEdit;
        CommentEventLine = new QLineEdit;

    //Календарь для выбора даты
        Calendar = new QCalendarWidget;
        Calendar->setGridVisible(true);

    //Соединяем сигналы и слоты
        connect(Calendar, SIGNAL(selectionChanged()), this, SLOT(SelectedDateChanged()));
        connect(OKButton, SIGNAL(clicked()), this, SLOT(OKClicked()));
        connect(OKButton, SIGNAL(clicked()), this, SLOT(accept()));
        connect(AddButton, SIGNAL(clicked()), this, SLOT(AddClicked()));

    //добавляем виджеты на layout'ы
        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(HeadingLabel,0,0,1,2,Qt::AlignCenter);
        mainLayout->addWidget(DataLabel,1,0);
        mainLayout->addWidget(Calendar, 1, 1);
        mainLayout->addWidget(EventLabel,3,0);
        mainLayout->addWidget(CommentLabel,4,0);
        mainLayout->addWidget(NameEventLine,3,1);
        mainLayout->addWidget(DateEventLine,2,1);
        mainLayout->addWidget(CommentEventLine,4,1);
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(AddButton);
        buttonLayout->addWidget(OKButton);
        mainLayout->addLayout(buttonLayout,5,0,1,2);
        setLayout(mainLayout);
        setWindowTitle(tr("Добавление события"));
}

//Слот для диалогового окна добавления события -
//изменение даты в календаре пользователем
void AddEventDialog::SelectedDateChanged()
{
    QDate Date = Calendar->selectedDate();
    DateEventLine->setText(Date.toString("dd-MM-yy"));
}

//Слот для диалогового окна добавления события -
//нажатие на кнопку Добавить
void AddEventDialog::AddClicked()
{
    QString Data = DateEventLine->text();
    QString Name = NameEventLine->text();
    QString Comment = CommentEventLine->text();
    //Проверка наличия пустых полей
    if (Data == "" || Name == "" || Comment == ""){
        QMessageBox::information(this, tr("Пустое поле!"),
                     tr("Пожалуйста, заполните все поля!"));
                 return;
    } else {
        DateEvent = Data;
        NameEvent = Name;
        CommentEvent = Comment;
        DateEventLine->clear();
        NameEventLine->clear();
        CommentEventLine->clear();
        AddButton->setEnabled(false);
        OKButton->setEnabled(true);
    }
}

//Слот для диалогового окна добавления события -
//нажатие на кнопку Готово
void AddEventDialog::OKClicked()
{
    OKButton->setEnabled(false);
    AddButton->setEnabled(true);
    close();
}

//Функции для диалогового окна добавления события

//1) Возврат выбранной даты события
QString AddEventDialog::getDateEvent()
{
    return DateEvent;
}
//2) Возврат выбранного названия события
QString AddEventDialog::getNameEvent()
{
    return NameEvent;
}
//3) Возврат выбранного комментария события
QString AddEventDialog::getCommentEvent()
{
    return CommentEvent;
}
