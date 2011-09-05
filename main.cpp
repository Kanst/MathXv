#include <QtGui>
#include "one.h"
#include "calc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    one  w;
    w.show();
    return a.exec();
}
