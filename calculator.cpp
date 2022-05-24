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
    connect(Calculator::findChild<QPushButton*>("plus"),
            SIGNAL(released()), this, SLOT(mathButtonPressed()));
    connect(Calculator::findChild<QPushButton*>("minus"),
            SIGNAL(released()), this, SLOT(mathButtonPressed()));
    connect(Calculator::findChild<QPushButton*>("divide"),
            SIGNAL(released()), this, SLOT(mathButtonPressed()));
    connect(Calculator::findChild<QPushButton*>("times"),
            SIGNAL(released()), this, SLOT(mathButtonPressed()));
    connect(Calculator::findChild<QPushButton*>("equals"),
            SIGNAL(released()), this, SLOT(equalButton()));
    connect(Calculator::findChild<QPushButton*>("clear"),
            SIGNAL(released()), this, SLOT(clearPressed()));
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

void Calculator::emptyBuffer(){
    m_numBuffer = "";
    ui->display->setText("");
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
    QPushButton* btn = (QPushButton*)sender();
    m_calcVal = m_numBuffer.toDouble();
    emptyBuffer();
    m_currentOp = m_opMap[btn->text()];
}

void Calculator::equalButton(){
    double numBuffDbl = m_numBuffer.toDouble();
    switch(m_currentOp){
    case none:
        break;
    case plus:
        numBuffDbl = m_calcVal + numBuffDbl;
        break;
    case min:
        numBuffDbl = m_calcVal - numBuffDbl;
        break;
    case div:
        numBuffDbl = m_calcVal / numBuffDbl;
        break;
    case mult:
        numBuffDbl = m_calcVal * numBuffDbl;
        break;
    }
    setBuffer(QString::number(numBuffDbl));
}

void Calculator::clearPressed(){
    setBuffer(0);
}
void Calculator::changeNumSign(){

}

