#include <QApplication>
#include "Mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Mainwindow main;
    main.show();
    return app.exec();
}
