#include <QApplication>
#include "mydialog.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog dlg;
    dlg.show();
    return a.exec();
}
