#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT
    enum Op { none, plus, min, div, mult };
public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    double m_calcVal;
    Op m_currentOp;
    QString m_numBuffer;
    void setBuffer(QString val);
    void updateBuffer(QString val);
private slots:
    void numPressed();
    void mathButtonPressed();
    void equalButton();
    void changeNumSign();
};
#endif // CALCULATOR_H
