/*****************************************************************
** Programming challenges v1.4 - 02 Temperature Converter
** Marcin Ligeza 2019
*****************************************************************/


#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QWidget>

namespace Ui {
class TemperatureConverter;
}

class TemperatureConverter : public QWidget
{
    Q_OBJECT

public:
    explicit TemperatureConverter(QWidget *parent = nullptr);
    ~TemperatureConverter();

private slots:
    void on_celcius_valueChanged(double value);
    void on_kelvin_valueChanged(double value);
    void on_fahrenheit_valueChanged(double value);

private:
    Ui::TemperatureConverter *ui;
};

#endif // TEMPERATURECONVERTER_H
