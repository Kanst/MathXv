#include "matr.h"
#include "ui_matr.h"
#include "one.h"

Matr::Matr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Matr)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
       QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
       this->setWindowFlags(Qt::Window);
       ui->setupUi(this);
      // begin();
       connect(ui->lineEdit_4 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit_3 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit_2 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit ,  SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->result,SIGNAL(clicked(bool)),this,SLOT(begin()));
       connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Matr::~Matr()
{
    delete ui;
}

void Matr::begin()

{
    bool Ok=true,OOk=true,Okk=true,KKK=true;
    int xx,yy,zz,cc;
    xx = ui->lineEdit_4->text().toInt(&Ok,10);
    yy = ui->lineEdit_2->text().toInt(&OOk,10);
    zz = ui->lineEdit_3->text().toInt(&Okk,10);
    cc = ui->lineEdit->text().toInt(&KKK,10);
    if (xx != yy || zz !=cc)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку(Разная размерность матриц"),
            QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
    bool t=true;
    QString buf,buf1,buf2;
    double ijA,ijB,result1,result2,result;
    ui->tableWidget_4->setRowCount(xx);
    ui->tableWidget_4->setColumnCount(zz);
    for(int i=0; i<=xx; i++)
        for (int j=0;j<=zz; j++)
        {
            ui->tableWidget_4->horizontalHeader()->resizeSection(j,50);
            ui->tableWidget_4->verticalHeader()->resizeSection(i,50);
        }

    for(int i=0; i<xx; i++)
        for (int j=0;j<zz; j++)
        {
            buf1 = ui->tableWidget->item(i,j)->text();
            result1 = buf1.toDouble(&t);
            if (t == false)
            {
                QMessageBox msgBox(QMessageBox::Information,
                    ("Error"),
                    ("Ошибка.Обратитесь в справку.(Введено неверное значение)"),
                    QMessageBox::Ok);
                msgBox.exec();
                QTableWidgetItem *newitem= new QTableWidgetItem();
                newitem->setText("0");
                ui->tableWidget->setItem(i,j,newitem);
            }
            else
            {
            buf2 = ui->tableWidget_2->item(i,j)->text();
            result2 = buf2.toDouble(&t);
            if (t == false)
            {
                QMessageBox msgBox(QMessageBox::Information,
                    ("Error"),
                    ("Ошибка.Обратитесь в справку.(Введено неверное значение)"),
                    QMessageBox::Ok);
                msgBox.exec();
                QTableWidgetItem *newitem= new QTableWidgetItem();
                newitem->setText("0");
                ui->tableWidget_2->setItem(i,j,newitem);

            }
            else
            {
            if (ui->radioButton->isChecked())
            result = result1 + result2;
            else
            result = result1 - result2;
            buf.setNum(result,6,6);
            ui->tableWidget_4->setItem(i,j,new QTableWidgetItem(buf));
            }
            }
        }
    }
}

void Matr::begin2()
{

    int mA,mB,nA,nB;
    QString strmA,strnA,strmB,strnB;
    strmA = ui->lineEdit_4->text();
    mA   = strmA.toInt();
    strnA = ui->lineEdit_3->text();
    nA = strnA.toInt();
    ui->tableWidget->setRowCount(mA);
    ui->tableWidget->setColumnCount(nA);

    for(int i=0; i<=mA; i++)
        for (int j=0;j<=nA; j++)
        {
            QTableWidgetItem *newitem= new QTableWidgetItem();
            newitem->setText("0");
            ui->tableWidget->horizontalHeader()->resizeSection(j,30);
            ui->tableWidget->verticalHeader()->resizeSection(i,30);
            ui->tableWidget->setItem(i,j,newitem);
        }

    strmB = ui->lineEdit_2->text();
    mB   = strmB.toInt();
    strnB = ui->lineEdit->text();
    nB = strnB.toInt();
    ui->tableWidget_2->setRowCount(mB);
    ui->tableWidget_2->setColumnCount(nB);
    for(int i=0; i<= mB; i++)
        for (int j=0;j<=nB; j++)
        {
            QTableWidgetItem *newitem= new QTableWidgetItem();
            newitem->setText("0");
            ui->tableWidget_2->horizontalHeader()->resizeSection(j,30);
            ui->tableWidget_2->verticalHeader()->resizeSection(i,30);
             ui->tableWidget_2->setItem(i,j,newitem);
        }
    bool Ok=true,OOk=true,Okk=true,KKK=true;
    int xx,yy,zz,cc;
    xx = ui->lineEdit_4->text().toInt(&Ok,10);
    yy = ui->lineEdit_2->text().toInt(&OOk,10);
    zz = ui->lineEdit_3->text().toInt(&Okk,10);
    cc = ui->lineEdit->text().toInt(&KKK,10);
    if (Ok == false || OOk == false || Okk == false || KKK == false)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку.(Введено неверное значение)"),
            QMessageBox::Ok);
        msgBox.exec();
        if (Ok == false)
            ui->lineEdit_4->setText("0");
        if (Okk == false)
            ui->lineEdit_3->setText("0");
        if (OOk == false)
            ui->lineEdit_2->setText("0");
        if (KKK== false)
            ui->lineEdit->setText("0");
    }
}

void Matr::close1()
{
   one *w3 = new one();
   w3->show();
   close();
}
