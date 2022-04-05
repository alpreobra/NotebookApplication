#include "notebook.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Notebook *notebook = new Notebook;
    notebook -> showMaximized();
    notebook->show();

    return app.exec();
}
