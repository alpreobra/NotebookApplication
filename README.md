# NotebookApplication
Приложение "Записная книжка" по Прикладному программированию

Проект включает в себя следующие файлы:

main.cpp - основной файл программы
notebook.cpp, notebook.h - Записная книжка

add_contact_dialog.cpp, add_contact_dialog.h - диалоговое окно добавления контакта в Телефонную книгу
find_contact_by_fio_dialog.cpp, find_contact_by_fio_dialog.h - диалоговое окно поиска контакта по фамилии
find_contact_by_phonenumber_dialog.cpp, find_contact_by_phonenumber_dialog.h - диалоговое окно поиска контакта по номеру телефона
find_contact_by_who_dialog.cpp, find_contact_by_who_dialog.h - диалоговое окно поиска контакта по его роли (то есть кем он является)

add_event_dialog.cpp, add_event_dialog.h - диалоговое окно добавления события в Журнал событий
find_event_by_date_dialog.cpp, find_event_by_date_dialog.h - диалоговое окно поиска события по дате
find_event_by_name_dialog.cpp, find_event_by_name_dialog.h - диалоговое окно поиска события по названию

add_task_dialog.cpp, add_task_dialog.h - диалоговое окно добавления дела в Журнал дел
find_task_by_date_dialog.cpp, find_task_by_date_dialog.h - диалоговое окно поиска дела по дате
Описание приложения "Записная книжка"

IDE: QTCreator
Язык программирования: C++
Технология для реализации GUI: Фреймворк QT
Приложение "Записная книжка" будет предназначено для хранения пользователем своих контактов телефонной книги, напоминаний о важных событиях и заметок о планируемых делах на день.
Приложение "Записная книжка" будет включать три компоненты: Телефонную книгу, Журнал событий и Журнал дел. Для каждой компоненты возможно добавление в БД, удаление, а также выполнение поиска по определенным параметрам и вывод результатов поиска.
Телефонная книга предназначена для хранения информации о контактах пользователя. Информация, которая будет храниться в Телефонной книге: ФИО, Номер телефона, E-mail (при наличии), "Кто это" - информация о том, кем является контакт - например, родственник, врач, автосервис и т. д. Возможен поиск и просмотр отдельных записей по ФИО, Номеру телефона, Информации "Кто это".
Журнал событий предназначен для хранения информации о различных праздниках, мероприятиях, важных встречах и т. д. Информация, которая будет храниться в Журнале событий: Дата события, Что за событие, Комментарий к событию. Возможен поиск и просмотр отдельных записей по Дате события и Названию события.
Журнал дел предназначен для хранения списка дел на разные даты. Информация, которая будет храниться в Журнале дел: Дата, Дело, Комментарий. Возможен поиск и просмотр дел на конкретную Дату.
