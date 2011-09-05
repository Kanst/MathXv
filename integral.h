/*
 * Форма анализа функции
 * Авраменко Евгений АК5-31
 *
 * Производит анализ фукции(вычисление производной и подсчет интеграла(3 способа)).
 */


#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class integral;
}

class integral : public QDialog
{
    Q_OBJECT

public:
    explicit integral(QWidget *parent = 0);
    ~integral();

private:
    Ui::integral *ui;

public slots:
  void closse();
  void begin1();
  void begin2();
};

#endif // INTEGRAL_H
