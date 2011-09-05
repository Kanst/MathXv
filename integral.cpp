/*
 * ����� ������� �������
 * ��������� ������� ��5-31
 *
 * ���������� ������ ������(���������� ����������� � ������� ���������(3 �������)).
 */


#include "integral.h"
#include "ui_integral.h"
#include "one.h"
#include "difinpoint.h"
#include "opredint.h"

integral::integral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::integral)
{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(closse()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(begin1()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(begin2()));

}

integral::~integral()
{
    delete ui;
}

///����� ��������� �����,�������� �������
void integral::closse()
{
    close();
    one  *w4 = new one();
    w4->show();
}

///����� ����� �������� �����������,�������� �������
void integral::begin1()
{
    close();
    difinpoint *ddif = new difinpoint();
    ddif->show();
}

///����� ����� �������� ���������,�������� �������
void integral::begin2()
{
    close();
    opredint *opre = new opredint();
    opre->show();
}


