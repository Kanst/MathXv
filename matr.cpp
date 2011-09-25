#include "matr.h"
#include "ui_matr.h"
#include "one.h"
#include "determ.cpp"

Matr::Matr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Matr)
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
       QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
       this->setWindowFlags(Qt::Window);
       ui->setupUi(this);
       ui->lineEdit_6->setVisible(false);
       ui->lineEdit_5->setVisible(false);
       ui->label_6->setVisible(false);
       ui->label_7->setVisible(false);
       connect(ui->lineEdit_4 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit_3 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit_2 ,SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->lineEdit ,  SIGNAL(editingFinished()),this,SLOT(begin2()));
       connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(begin()));
       connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close1()));
       connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(determinant()));
       connect(ui->result,SIGNAL(clicked(bool)),this,SLOT(proizved()));
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
    zz = ui->lineEdit_2->text().toInt(&OOk,10);
    yy = ui->lineEdit_3->text().toInt(&Okk,10);
    cc = ui->lineEdit->text().toInt(&KKK,10);
    if (xx != zz || yy !=cc)
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
    ui->tableWidget_4->setRowCount(yy);
    ui->tableWidget_4->setColumnCount(xx);
    for(int i=0; i<=xx; i++)
        for (int j=0;j<=yy; j++)
        {
            ui->tableWidget_4->horizontalHeader()->resizeSection(i,50);
            ui->tableWidget_4->verticalHeader()->resizeSection(j,50);
        }

    for(int i=0; i<yy; i++)
        for (int j=0;j<xx; j++)
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
            buf.setNum(result);
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
    ui->tableWidget->setRowCount(nA);
    ui->tableWidget->setColumnCount(mA);

    for(int i=0; i<=mA; i++)
        for (int j=0;j<=nA; j++)
        {
            QTableWidgetItem *newitem= new QTableWidgetItem();
            newitem->setText("0");
            ui->tableWidget->horizontalHeader()->resizeSection(i,30);
            ui->tableWidget->verticalHeader()->resizeSection(j,30);
            ui->tableWidget->setItem(j,i,newitem);
        }

    strmB = ui->lineEdit_2->text();
    mB   = strmB.toInt();
    strnB = ui->lineEdit->text();
    nB = strnB.toInt();
    ui->tableWidget_2->setRowCount(nB);
    ui->tableWidget_2->setColumnCount(mB);
    for(int i=0; i<= mB; i++)
        for (int j=0;j<=nB; j++)
        {
            QTableWidgetItem *newitem= new QTableWidgetItem();
            newitem->setText("0");
            ui->tableWidget_2->horizontalHeader()->resizeSection(i,30);
            ui->tableWidget_2->verticalHeader()->resizeSection(j,30);
             ui->tableWidget_2->setItem(j,i,newitem);
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
    ui->lineEdit_6->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
}

void Matr::close1()
{
   one *w3 = new one();
   w3->show();
   close();
}

void Matr::proizved()
{
    bool Ok=true,OOk=true,Okk=true,KKK=true;
    int xx,yy,zz,cc;
    xx = ui->lineEdit_4->text().toInt(&Ok,10);
    zz = ui->lineEdit_2->text().toInt(&OOk,10);
    yy = ui->lineEdit_3->text().toInt(&Okk,10);
    cc = ui->lineEdit->text().toInt(&KKK,10);
    if (xx > 100 || yy > 100 || zz > 100 || cc > 100)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку(Размерность должны быть меньше 100)"),
            QMessageBox::Ok);
        msgBox.exec();
        ui->lineEdit_4->setText("0");
        ui->lineEdit_3->setText("0");
        ui->lineEdit_2->setText("0");
        ui->lineEdit->setText("0");
    }
    else
    if (yy != zz)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку(Количество столбцов первой матрицы должно быть равно количеству строк второй)"),
            QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
    bool t=true;
    double matr1[100][100], matr2[100][100] , rezmatr[100][100];
    QString buf,buf1,buf2;
    double ijA,ijB,result1,result2,result;
    ui->tableWidget_4->setRowCount(yy);
    ui->tableWidget_4->setColumnCount(yy);
    for(int i=0; i<=yy; i++)
        for (int j=0;j<=yy; j++)
        {
            ui->tableWidget_4->horizontalHeader()->resizeSection(i,50);
            ui->tableWidget_4->verticalHeader()->resizeSection(j,50);
        }

    for(int i=0; i<yy; i++)
        for (int j=0;j<xx; j++)
        {
           buf1 = ui->tableWidget->item(i,j)->text();
           matr1 [i][j] = buf1.toDouble(&t);
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
        }

    for(int i=0; i<cc; i++)
        for (int j=0;j<zz; j++)
        {
           buf1 = ui->tableWidget_2->item(i,j)->text();
           matr2 [i][j] = buf1.toDouble(&t);
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
        }

    for(int i=0; i<yy; i++)
        for (int j=0;j<yy; j++)
        {

               rezmatr[i][j] = 0;

        }

    for(int i=0; i<yy; i++)
        for (int j=0;j<yy; j++)
        {
           for (int k = 0 ; k <= yy ; k++)
           {
               rezmatr[i][j] =rezmatr[i][j] + matr1[i][k]*matr2[k][j];
           }
        }

    for(int i=0; i<=yy; i++)
        for (int j=0;j<=yy; j++)
        {
            buf.setNum(rezmatr [i][j]);
            ui->tableWidget_4->setItem(i,j,new QTableWidgetItem(buf));
        }
    }
}

void Matr::determinant()
{
    bool Ok=true,OOk=true,Okk=true,KKK=true;
    int xx,yy,zz,cc;
    xx = ui->lineEdit_4->text().toInt(&Ok,10);
    zz = ui->lineEdit_2->text().toInt(&OOk,10);
    yy = ui->lineEdit_3->text().toInt(&Okk,10);
    cc = ui->lineEdit->text().toInt(&KKK,10);
    if (xx > 100 || yy > 100 || zz > 100 || cc > 100)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку(Размерность должны быть меньше 100)"),
            QMessageBox::Ok);
        msgBox.exec();
            ui->lineEdit_4->setText("0");
            ui->lineEdit_3->setText("0");
            ui->lineEdit_2->setText("0");
            ui->lineEdit->setText("0");
    }
    else
    if (xx != yy || zz != cc)
    {
        QMessageBox msgBox(QMessageBox::Information,
            ("Error"),
            ("Ошибка.Обратитесь в справку(Матрица должна быть квадратной)"),
            QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
    bool t=true;
    double **matr1 = new double * [xx],**matr2 = new double * [xx];
    for(int i = 0; i < xx; i++)
            {
                matr1[i] = new double[xx];
                matr2[i] = new double[xx];
            }
    QString buf,buf1,buf2;
    double ijA,ijB,result1,result2,result;

    for(int i=0; i<yy; i++)
        for (int j=0;j<xx; j++)
        {
           buf1 = ui->tableWidget->item(i,j)->text();
           matr1 [i][j] = buf1.toDouble(&t);
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
        }

    for(int i=0; i<cc; i++)
        for (int j=0;j<zz; j++)
        {
           buf1 = ui->tableWidget_2->item(i,j)->text();
           matr2 [i][j] = buf1.toDouble(&t);
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
        }
    ui->lineEdit_6->setVisible(true);
    ui->lineEdit_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_7->setVisible(true);
    result1 = Det(matr1,xx);
    result2 = Det(matr2,xx);
    QString dett1,dett2;
    dett1.setNum(result1);
    dett2.setNum(result2);
    ui->lineEdit_6->setText(dett2);
    ui->lineEdit_5->setText(dett1);

    }
}
