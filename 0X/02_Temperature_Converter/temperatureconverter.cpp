/*****************************************************************
** Programming challenges v1.4 - 02 Temperature Converter
** Marcin Ligeza 2019
*****************************************************************/

#include "temperatureconverter.h"
#include "ui_temperatureconverter.h"

TemperatureConverter::TemperatureConverter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureConverter)
{
    ui->setupUi(this);
}

TemperatureConverter::~TemperatureConverter()
{
    delete ui;
}

void TemperatureConverter::on_celcius_valueChanged(double value)
{
    ui->debugConsole->setText(QString::number(value));
    double kelvinDegree = value - 273.15;
    double fahrenheitDegree = 32.0 + value*9.0/5.0;
    ui->kelvin->setValue(kelvinDegree);
    ui->fahrenheit->setValue(fahrenheitDegree);
}

void TemperatureConverter::on_kelvin_valueChanged(double value)
{
    ui->debugConsole->setText(QString::number(value));
    double celciusDegree = value + 273.15;
    double fahrenheitDegree = 32.0 + celciusDegree*9.0/5.0;
    ui->celcius->setValue(celciusDegree);
    ui->fahrenheit->setValue(fahrenheitDegree);
}

void TemperatureConverter::on_fahrenheit_valueChanged(double value)
{
    ui->debugConsole->setText(QString::number(value));
    double kelvinDegree = (value-32)*5.0/9.0;
    double celciusDegree = kelvinDegree+273.15;
    ui->kelvin->setValue(kelvinDegree);
    ui->celcius->setValue(celciusDegree);
}
