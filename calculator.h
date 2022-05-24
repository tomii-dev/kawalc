#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT
    enum Op { none, plus, min, div, mult };
    std::map<QString, Op> m_opMap = {
        {"+", plus},
        {"-", min},
        {"/", div},
        {"*", mult}
    };
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
    void emptyBuffer();
    void clear();
private slots:
    void numPressed();
    void mathButtonPressed();
    void equalButton();
    void clearPressed();
    void changeNumSign();
};
#endif // CALCULATOR_H
