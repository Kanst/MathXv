#ifndef MATR_H
#define MATR_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class Matr;
}

class Matr : public QDialog
{
    Q_OBJECT

public:
    explicit Matr(QWidget *parent = 0);
    ~Matr();

private:
    Ui::Matr *ui;

public slots:
  void begin();
  void begin2();
  void close1();
};

#endif // MATR_H
