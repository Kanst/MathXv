/*
 * Начальная форма
 * Авраменко Евгений АК5-31
 *
 * Производит выбор действия
 */
 
#include "one.h"
#include "ui_one.h"
#include "integral.h"
#include "calc.h"
#include "matr.h"
#include "spravka.h"

one::one(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::one)
{
     ui->setupUi(this);
     ///Сигналы
     connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(begin1()));
     connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(begin1()));
     connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(analiz()));
     connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(analiz()));
     connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
     connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(close1()));
     connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(close1()));
     connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(spravka1()));
     connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(spravka1()));
   //  one::setPalette(Qt::gray);
}

one::~one()
{
    delete ui;
}

///Вызов формы подсчета выражения,закрытие текущей
void one::begin1()
{
    Calc  *w2 = new Calc();
    w2->show();
    close();
}

///Вызов формы анализа функции,закрытие текущей
void one::analiz()
{
    integral *an = new integral();
    an->show();
    close();
}

void one::close1()
{
    Matr *w3 = new Matr();
    w3->show();
    close();
}

void one::spravka1()
{
    Spravka *w3 = new Spravka();
    w3->show();
    close();

}
