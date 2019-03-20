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

void Restrict(const QString &arg, QLineEdit *le, int &lab)
{
    int value = arg.toInt();
    if(value > 10)
        value = 10;
    if(value < 0)
        value = 0;
    le->setText(QString::number(value));
    lab = value;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Restrict(arg1, ui->lineEdit, Lab1);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    Restrict(arg1, ui->lineEdit_2, Lab2);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
     Restrict(arg1, ui->lineEdit_3, Lab3);
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
     Restrict(arg1, ui->lineEdit_4, Ex);
}

