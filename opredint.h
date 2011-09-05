/*
 * Форма подсчета интеграла
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление определенного интеграла,записанного в строку
 */

#ifndef OPREDINT_H
#define OPREDINT_H

#include <QDialog>

namespace Ui {
    class opredint;
}

class opredint : public QDialog
{
    Q_OBJECT

public:
    explicit opredint(QWidget *parent = 0);
    ~opredint();

private:
    Ui::opredint *ui;

public slots:
  void otvet1();
  void closse1();
  void begin1();
};

#endif // OPREDINT_H
