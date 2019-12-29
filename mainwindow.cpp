#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

using namespace std;

string src="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
string src1="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
string src2="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
string src3="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
string src4="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
string src5="/home/techbridge/Videos/Elon Musk's Ultimate Advice for Students & College Grads - HOW TO SUCCEED IN LIFE.mp4";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*****{start all the deamons}*****/

    ui->label->startdeamon(src);
    //ui->label_2->startdeamon(src1);
    //ui->label_3->startdeamon(src2);
    //ui->label_4->startdeamon(src3);
    //ui->label_5->startdeamon(src4);
    //ui->label_6->startdeamon(src5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->startdeamon(src);
    ui->label_2->startdeamon(src1);
    ui->label_3->startdeamon(src2);
    ui->label_4->startdeamon(src3);
    ui->label_5->startdeamon(src4);
    ui->label_6->startdeamon(src5);
}
