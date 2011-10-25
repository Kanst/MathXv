#include "spravka.h"
#include "ui_spravka.h"
#include "one.h"

Spravka::Spravka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spravka)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close1()));
    Spravka::setPalette(Qt::gray);
}

Spravka::~Spravka()
{
    delete ui;
}

void Spravka::close1()
{
    close();
    one  *w3 = new one();
    w3->show();
}




