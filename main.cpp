#include "mainwindow.h"
#include <QApplication>
#include "Model/model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //BinaryView *v1=new BinaryView(this);
    w.show();
    return a.exec();
}
