#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qprocess.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initUI();
    //killProcess();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    m_widget1 = new QWidget();
    m_widget1->setStyleSheet("background-color:red");
    m_widget1->setGeometry(0,0,100,100);
    //ui->stackedWidget->addWidget(m_widget1);
    //ui->stackedWidget->setCurrentWidget(m_widget1);

    //ui->stackedWidget->setStyleSheet("background-color:yellow");
    //ui->stackedWidget->setGeometry(0,0,200,200);

    ui->centralWidget->setStyleSheet("background-color:blue");

    //ui->statusBar->setStyleSheet("background-color:black");
    ui->menuBar->setStyleSheet("background-color:yellow");
    //ui->mainToolBar->setStyleSheet("background-color:green");

}
void MainWindow::killProcess(int miniute)
{
    if(m_timer)
        m_timer->stop();
    if(m_timer == nullptr)
    {
        m_timer = new QTimer();
        m_timer->setSingleShot(false);
        m_timer->setInterval(1000);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timer()));
    }
    m_maxSeconds = 60*miniute;
    m_seconds = 0;
    m_timer->start(1000);

}

void MainWindow::on_timer()
{
    m_seconds += 1;
    if(m_seconds >= m_maxSeconds)
    {
        m_timer->stop();
        QString c = "killall QQLive";
        int pInt = QProcess::execute(c);
        qDebug()<<pInt<<endl;
    }
    int min = (m_maxSeconds-m_seconds)/60;
    int sec = (m_maxSeconds-m_seconds)%60;
    QString str;
    str.sprintf("剩余%d分%d秒",min,sec);

    ui->label->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    killProcess(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    killProcess(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    killProcess(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    killProcess(5);
}

void MainWindow::on_pushButton_5_clicked()
{
    killProcess(10);
}

void MainWindow::on_pushButton_6_clicked()
{
    killProcess(20);
}
