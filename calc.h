/*
 * Форма калькулятора
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление выражения,записанного в строку
 */
 
#ifndef CALC_H
#define CALC_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class Calc;
}

class Calc : public QDialog
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private:
    Ui::Calc *ui;

public slots:
    void begin();
    void calc();
    void closse();
};

#endif // CALC_H
