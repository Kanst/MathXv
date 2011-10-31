/*
 * Форма вычисления производной
 * Авраменко Евгений АК5-31
 *
 * Производит вычисление производной функции в точке(функция записана в строку).
 */
 
#include "difinpoint.h"
#include "ui_difinpoint.h"
#include "integral.h"
#include "text_analiz.h"
#include "dif_int.h"
#include "postfix_result_and_stroka_postfix.h"


difinpoint::difinpoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::difinpoint)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    this->setWindowFlags(Qt::Window);
    ui->setupUi(this);
    begin1();
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(closse1()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(otvet1()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(otvet1()));
   // difinpoint::setPalette(Qt::gray);
}

difinpoint::~difinpoint()
{
    delete ui;
}

void difinpoint::begin1()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setVisible(true);
    ui->lineEdit->setFocus();
    ui->pushButton_3->setDefault(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setFocus();
}

void difinpoint::otvet1()
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
    str[str.length()+1]='+';
    str[str.length()+2]='0';
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

    if (output1[0] == 'E')
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
        r = dif_in_point(input1,x,y);
        str.setNum(r);
        ui->outputEdit->setText(str);
        ui->outputEdit->setEnabled(true);
        ui->outputEdit->setVisible(true);
        ui->pushButton_3->setDefault(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setFocus();
    }

}

///Вызов предыдущей формы и закрытие текущей
void difinpoint::closse1()
{
    close();
    integral *inn = new integral();
    inn->show();
}


