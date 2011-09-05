/*
 * Форма калькулятора
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление выражения,записанного в строку
 */
 
#ifndef DIFINPOINT_H
#define DIFINPOINT_H

#include <QDialog>
#include <QtGui>


namespace Ui {
    class difinpoint;
}

class difinpoint : public QDialog
{
    Q_OBJECT

public:
    explicit difinpoint(QWidget *parent = 0);
    ~difinpoint();

private:
    Ui::difinpoint *ui;

public slots:
  void otvet1();
  void closse1();
  void begin1();

};
#endif // DIFINPOINT_H
