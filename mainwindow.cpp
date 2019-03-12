#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

int Lab1;
int Lab2;
int Lab3;
int Ex;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(textChanged(const QString &texts)), this, SLOT(on_lineEdit_inputRejected()));
    connect(ui->lineEdit_2, SIGNAL(clicked()), this, SLOT(on_lineEdit_2_inputRejected()));
    connect(ui->lineEdit_3, SIGNAL(clicked()), this, SLOT(on_lineEdit_3_inputRejected()));
    connect(ui->lineEdit_4, SIGNAL(clicked()), this, SLOT(on_lineEdit_4_inputRejected()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(CalculatingSem()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(CalculatingRes()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CalculatingSem()
{
    double Sem= (Lab1+Lab2+Lab3)/3;
    QString res = QString:: number(Sem, 'g', 1);
    ui->lineEdit_5->setText(res);
}

void MainWindow::CalculatingRes()
{
    double Res=0;
    Res = ((Lab1+Lab2+Lab3)/3*0.4) + (Ex*0.6);
    QString res = QString:: number(Res, 'g', 1);
    ui->lineEdit_6->setText(res);
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox:: StandardButton exit= QMessageBox::question (this, "Выход", "Вы действительно хотите выйти?",
                           QMessageBox::Yes | QMessageBox::No);
    if (exit==QMessageBox::Yes){
        QApplication::quit();
    }
    else{
        qDebug()<< "Отказ выхода";
    }
}

void MainWindow::on_lineEdit_inputRejected()
{
    Lab1=(ui->lineEdit->text()).toInt();
}

void MainWindow::on_lineEdit_2_inputRejected()
{
    Lab2=(ui->lineEdit_2->text()).toInt();
}


void MainWindow::on_lineEdit_3_inputRejected()
{
     Lab3=(ui->lineEdit_3->text()).toInt();
}

void MainWindow::on_lineEdit_4_inputRejected()
{
    Ex=(ui->lineEdit_4->text()).toInt();
}
