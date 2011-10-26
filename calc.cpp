/*
 * Форма калькулятора
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление выражения,записанного в строку
 */

#include "calc.h"
#include "ui_calc.h"
#include "postfix_result_and_stroka_postfix.cpp"
#include "text_analiz.cpp"
#include "one.h"
#include <QFile>

 Calc::Calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calc)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    this->setWindowFlags(Qt::Window);
    ui->setupUi(this);
    begin();
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(closse()));
    ///Сигнал рассчета выражения
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(calc()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(calc()));
   // Calc::setPalette(Qt::gray);
}

Calc::~Calc()
{
    delete ui;
}

///Параметры отображения
void Calc::begin()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setVisible(true);
    ui->lineEdit->setFocus();
    ui->pushButton->setDefault(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton->setFocus();
}
///Рассет
void Calc::calc()
{
    bool Ok=false;
    /*
    r-result
    x,y-переменные
    */
    float r,x=0,y=0;
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
    output1=vixod(input1);
    ///Сообщение об ошибке
    if (output1 == "Error")
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку."),
            QMessageBox::Ok);
        msgBox.exec();
        ui->outputEdit->setText("Error!!");
        ui->outputEdit->setEnabled(true);
        ui->outputEdit->setVisible(true);
        ui->pushButton->setFocus();
    }
   else
    {
		///Подсчет и вывод на экран
        r=polka(vixod(input1),x,y);
        str.setNum(r);
        ui->outputEdit->setText(str);
        ui->outputEdit->setEnabled(true);
        ui->outputEdit->setVisible(true);
        ui->pushButton->setDefault(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton->setFocus();
   }
}
///Вызов начальной формы,закрытие текущей
void Calc::closse()
{
    close();
    one  *w3 = new one();
    w3->show();
}
