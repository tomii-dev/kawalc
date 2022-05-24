#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent),
      m_calcVal(0.0),
      ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(400, 200));
    ui->display->setText(QString::number(m_calcVal));
    m_numBuffer = ui->display->text();
    QPushButton* numButtons[10];
    for(int i = 0; i < 10; i++){
        QString name = "button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton*>(name);
        connect(numButtons[i], SIGNAL(released()),
                this, SLOT(numPressed()));
    }
    /*connect(Calculator::findChild<QPushButton*>("equal"),
            SIGNAL(released()), this, SLOT(equalButton()));*/
}
Calculator::~Calculator()
{
    delete ui;
}

void Calculator::setBuffer(QString val){
    m_numBuffer = val;
    ui->display->setText(QString::number(m_numBuffer.toDouble(), 'g', 16));
}

void Calculator::updateBuffer(QString val){
    m_numBuffer += val;
    ui->display->setText(QString::number(m_numBuffer.toDouble(), 'g', 16));
}

void Calculator::numPressed(){
    QPushButton* btn = (QPushButton*)sender();
    QString valStr = btn->text();
    if(!m_numBuffer.toDouble()){
        setBuffer(valStr);
        return;
    }
    updateBuffer(valStr);
}

void Calculator::mathButtonPressed(){

}

void Calculator::equalButton(){

}

void Calculator::changeNumSign(){

}

