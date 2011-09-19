#ifndef SPRAVKA_H
#define SPRAVKA_H

#include <QDialog>

namespace Ui {
    class Spravka;
}

class Spravka : public QDialog
{
    Q_OBJECT

public:
    explicit Spravka(QWidget *parent = 0);
    ~Spravka();

private:
    Ui::Spravka *ui;
public slots:

};

#endif // SPRAVKA_H
