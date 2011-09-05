/*
 * Форма подсчета интеграла
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление определенного интеграла,записанного в строку
 */
 
#include "opredint.h"
#include "ui_opredint.h"
#include "text_analiz.h"
#include "dif_int.cpp"
#include "integral.h"

opredint::opredint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opredint)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    ui->setupUi(this);
     begin1();
     connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(closse1()));
     connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(otvet1()));
     connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(otvet1()));
}

opredint::~opredint()
{
    delete ui;
}

void opredint::closse1()
{
    close();
    integral *inn = new integral();
    inn->show();
}

void opredint::begin1()
{
    //ui->lineEdit->clear();
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setVisible(true);
    ui->lineEdit->setFocus();
    ui->pushButton_3->setDefault(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setFocus();
}

void opredint::otvet1()
{
    bool Ok=false;
    /*
    r-result
    x,y-переменные
    */
    float r,x=0,y=5;
    QString str,str_x,str_y;
    str =ui->lineEdit->text();
    str_x = ui->lineEdit_2->text();
    x = str_x.toDouble(&Ok);
    str_y = ui->lineEdit_3->text();
    y = str_y.toDouble(&Ok);
    char* value=new char[100];
    QByteArray ar = str.toAscii();
    char* sometext=ar.data();
    value=sometext;
    char *input1, *output1 ;
    input1 = output1 = new char [100];
    input1 = value;
   ///Преобразование строки
    input1 = proobraz(input1);
    input1 = len(input1,value);
    ///Перевод в польскую запись
    ///output1=vixod(input1);
    ///Вычисление методом прямоугольников
    if (ui->radioButton->isChecked())
    {
        r = int_pram(input1,x,y,1000);
    }
	///Вычисление методом Симпсона
    if (ui->radioButton_2->isChecked())
    {
        r = int_sims(input1,x,y);
    }
	///Вычисление методом трапеций 
    if (ui->radioButton_3->isChecked())
    {
        r = int_trap(input1,x,y,0.0001);
    }
    ///Вывод результата на экран
        str.setNum(r);
        ui->outputEdit->setText(str);
        ui->outputEdit->setEnabled(true);
        ui->outputEdit->setVisible(true);
        ui->pushButton_3->setDefault(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setFocus();
}
