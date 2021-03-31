#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter/presenter.h"
#include "View/binaryview.h"
#include <iostream>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(10,40);
    ui->spinBox_2->setRange(10,40);
    ui->horizontalSlider_2->setRange(2,30);
    ui->spinBox->setRange(2,30);
    //connect(ui->pushButton,SIGNAL(clicked()),);
    setWindowTitle("Parachute Project");

    //setFixedSize(1200,750);
    Model *model=new Model();
    _p=new Presenter();
    _p->setModel(model);
    _p->setView1(ui->widget);
    _p->setView2(ui->widget_2);
    ui->widget->setPresenter(_p);
    ui->widget_2->setPresenter(_p);
    /*for(int i=0;i<ui->widget_2->getVector().size();++i) {
        qWarning()<<ui->widget_2->getVector()[i];
    }*/
    connect(ui->action_quit,&QAction::triggered,this,&MainWindow::close);
    connect(ui->pushButton,SIGNAL(clicked()),ui->widget,SLOT(update()));
    connect(ui->pushButton,SIGNAL(clicked()),ui->widget_2,SLOT(update()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(updateMessage()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(updateNbSectors(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(updateNbPiste(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(changerSpinBox2Value(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(changerSpinBox1Value(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(changeSliderValue(int)));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeSlider2Value(int)));
    //connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(update))
    //connect(ui->spinBox,SIGNAL(valueChnaged()),this,SLOT(updateNbSectors(int)));
    //connect(ui->spinBox,SIGNAL(valueChnaged()),this,SLOT(updateNbSectors(int)));
    //qWarning()<<model->getLenMessage();
    //ui->widget->setVector();
    //_p->setModel(model);
    //_p->setVectorInt();
    //v1->setPresenter(p);
    //v1->setVector();
    //QVector<int> v=_p->getVector();
    //qWarning()<<v.at(0);

    //v1>setPresenter(p);
}


void MainWindow::updateMessage() {
    _p->setMessage(ui->lineEdit->text());
    qWarning()<<ui->lineEdit->text();
}
void MainWindow::updateNbSectors(int nb) {
    //qWarning()<<nb;
    ui->widget_2->updateNBSectors(nb);
}
void MainWindow::updateNbPiste(int nb) {
    ui->widget_2->updateNbPiste(nb);
}
void MainWindow::changerSpinBox2Value(int a) {
    ui->spinBox_2->setValue(a);
}
void MainWindow::changerSpinBox1Value(int a) {
    ui->spinBox->setValue(a);
}
void MainWindow::changeSliderValue(int a) {
    ui->horizontalSlider->setValue(a);
}
void MainWindow::changeSlider2Value(int a) {
    ui->horizontalSlider_2->setValue(a);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_action_About_us_triggered()
{
    QMessageBox::information(this,tr("About us"),tr("About us"));
}
