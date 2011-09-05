/*
 * Начальная форма
 * Авраменко Евгений АК5-31
 *
 * Производит выбор действия
 */

#ifndef ONE_H
#define ONE_H

#include <QDialog>

namespace Ui {
    class one;
}

class one : public QDialog
{
    Q_OBJECT

public:
    explicit one(QWidget *parent = 0);
    ~one();

private:
    Ui::one *ui;

public slots:
    void begin1();
    void analiz();
};

#endif // ONE_H
