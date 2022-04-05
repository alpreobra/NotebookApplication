#include <QtWidgets>
#include <add_task_dialog.h>

//============================================================================================
//+++++++++++++++ДИАЛОГОВОЕ ОКНО ДОБАВЛЕНИЯ ДЕЛА++++++++++++++++
//============================================================================================
//Конструктор диалогового окна добавления дела
AddTaskDialog::AddTaskDialog(QWidget *parent)
    : QDialog(parent)
{
        DateTask = "";
        NameTask = "";
        CommentTask = "";

    //Заголовок окна добавления дела
        QLabel *HeadingLabel = new QLabel(tr("Новое дело"));
        HeadingLabel->setStyleSheet("font-weight: bold; color: blue");
        QFont font("Arial",15);
        HeadingLabel->setFont(font);

    //Кнопки экрана добавления дела
        OKButton = new QPushButton(tr("&Готово"));
        OKButton->setEnabled(false);
        AddButton = new QPushButton(tr("&Добавить дело"));

    //Лейблы экрана добавления дела
        QLabel *DataLabel = new QLabel(tr("Дата выполнения"));
        QLabel *TaskLabel = new QLabel(tr("Что за дело"));
        QLabel *CommentLabel = new QLabel(tr("Комментарий"));

    //Текстовые поля экрана добавления дела
        DateTaskLine = new QLineEdit;
        DateTaskLine->setEnabled(false);
        NameTaskLine = new QLineEdit;
        CommentTaskLine = new QLineEdit;

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
        mainLayout->addWidget(TaskLabel,3,0);
        mainLayout->addWidget(CommentLabel,4,0);
        mainLayout->addWidget(NameTaskLine,3,1);
        mainLayout->addWidget(DateTaskLine,2,1);
        mainLayout->addWidget(CommentTaskLine,4,1);
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(AddButton);
        buttonLayout->addWidget(OKButton);
        mainLayout->addLayout(buttonLayout,5,0,1,2);
        setLayout(mainLayout);
        setWindowTitle(tr("Добавление дела"));
}

//Слот для диалогового окна добавления дела -
//изменение даты в календаре пользователем
void AddTaskDialog::SelectedDateChanged()
{
    QDate Date = Calendar->selectedDate();
    DateTaskLine->setText(Date.toString("dd-MM-yy"));
}

//Слот для диалогового окна добавления дела -
//нажатие на кнопку Добавить
void AddTaskDialog::AddClicked()
{
    QString Data = DateTaskLine->text();
    QString Name = NameTaskLine->text();
    QString Comment = CommentTaskLine->text();
    //Проверка наличия пустых полей
    if (Data == "" || Name == "" || Comment == ""){
        QMessageBox::information(this, tr("Пустое поле!"),
                     tr("Пожалуйста, заполните все поля!"));
                 return;
    } else {
        DateTask = Data;
        NameTask = Name;
        CommentTask = Comment;
        DateTaskLine->clear();
        NameTaskLine->clear();
        CommentTaskLine->clear();
        AddButton->setEnabled(false);
        OKButton->setEnabled(true);
    }
}

//Слот для диалогового окна добавления дела -
//нажатие на кнопку Готово
void AddTaskDialog::OKClicked()
{
    OKButton->setEnabled(false);
    AddButton->setEnabled(true);
    close();
}

//Функции для диалогового окна добавления дела

//1) Возврат выбранной даты дела
QString AddTaskDialog::getDateTask()
{
    return DateTask;
}

//2) Возврат выбранного названия дела
QString AddTaskDialog::getNameTask()
{
    return NameTask;
}

//3) Возврат выбранного комментария дела
QString AddTaskDialog::getCommentTask()
{
    return CommentTask;
}
