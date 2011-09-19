#include "spravka.h"
#include "ui_spravka.h"

Spravka::Spravka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spravka)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Spravka::~Spravka()
{
    delete ui;
}





