/*****************************************************************
** Programming challenges v1.4 - 02 Temperature Converter
** Marcin Ligeza 2019
*****************************************************************/

#include "temperatureconverter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TemperatureConverter w;
    w.show();
    return a.exec();
}
