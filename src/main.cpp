#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    button *key = new button(nullptr);

    key->show();
    return a.exec();
}
