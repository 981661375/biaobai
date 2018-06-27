   #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QCloseEvent>
#include<QPixmap>
#include<QMovie>
#include<QMessageBox>
#include <QPalette>
static int firstPageTime=1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("AHaaaaa");
    this->move(800,400);
    subw = new SubWidget();
    subw->move(this->pos().x()+100,this->pos().y()+100);
    subw->setAttribute(Qt::WA_ShowModal,true);//设置QWidget为模态
    //QPalette pal(this->palette());
    //pal.setColor(QPalette::Window,Qt::blue);
    //setPalette(pal);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if(firstPageTime==4)
    {
        QWidget::closeEvent(event);
    }else {
        QMessageBox::question(this,"","再think think!",QMessageBox::Ok);
    }

}



void MainWindow::on_yesButton_clicked()
{
    if(firstPageTime==1)
    {


        subw->SetContent("一次就答应了？要不试试其它？不然有种程序白写了的感觉。。",
                         "://Image/timg-7.gif",true);
        subw->show();
        connect(subw->Button,&QPushButton::clicked,[=]()
        {
            ui->yesButton->setText("不用想！我同意了");
            ui->noButton->setText("再想想。。。");
            ui->labelShow->setText("稳住。。");
            ui->labelImage_r->setPixmap(QPixmap(":/Image/65118018232225020.jpg"));
            subw->hide();
        });
        connect(subw,&SubWidget::close,[=]()
        {
            ui->yesButton->setText("不用想！我同意了");
            ui->noButton->setText("再想想。。。");
            ui->labelShow->setText("稳住。。");
            ui->labelImage_r->setPixmap(QPixmap(":/Image/65118018232225020.jpg"));
             subw->hide();
        });




        firstPageTime++;
    }else if(firstPageTime==2)
    {
        subw->SetContent("突如其来的惊喜。。。",
                         "://Image/timg-4.gif",true);
        subw->show();

        connect(subw->Button,&QPushButton::clicked,[=]()
        {
             ui->labelShow->setText("确定？似乎我有点紧张。。");
            ui->yesButton->setText("确定！！");
            ui->noButton->setText("没错！！");
            QMovie* movie = new QMovie(":/Image/img-006CqoO6ly1fq4iobtgaog307s0657wh.gif");
                ui->labelImage_r->setMovie(movie);
                ui->labelImage_r->setScaledContents(true);
                movie->start();
            subw->hide();
        });
        connect(subw,&SubWidget::close,[=]()
        {
            ui->labelShow->setText("确定？似乎我有点紧张。。");
           ui->yesButton->setText("确定！！");
           ui->noButton->setText("没错！！");
           QMovie* movie = new QMovie(":/Image/img-006CqoO6ly1fq4iobtgaog307s0657wh.gif");
               ui->labelImage_r->setMovie(movie);
               ui->labelImage_r->setScaledContents(true);
               movie->start();
             subw->hide();
        });

        firstPageTime++;
    }else if(firstPageTime==3)
    {
        ui->labelShow->setText("这就很好嘛！");
        ui->labelImage_r->setPixmap(QPixmap("://Image/822483909984675464.jpg"));

        ui->yesButton->hide();
        ui->noButton->hide();
        firstPageTime++;
    }
}

void MainWindow::on_noButton_clicked()
{
    if(firstPageTime==1)
    {
        subw->SetContent("。。。你看你，又不想一想？万一呢。。",
                         "://Image/timg-8.gif",true);
        subw->show();
        connect(subw->Button,&QPushButton::clicked,[=]()
        {
            ui->labelShow->setText("冷静。。缓一缓。。。");
            ui->yesButton->setText("那行！");
            ui->noButton->setText("等我想一想！");
            QMovie* movie = new QMovie("://Image/timg-9.gif");
                ui->labelImage_r->setMovie(movie);
                ui->labelImage_r->setScaledContents(true);
                movie->start();
            subw->hide();
        });
        connect(subw,&SubWidget::close,[=]()
        {
            ui->labelShow->setText("冷静。。缓一缓。。。");
            ui->yesButton->setText("那行！");
            ui->noButton->setText("等我想一想！");
            QMovie* movie = new QMovie("://Image/timg-9.gif");
                ui->labelImage_r->setMovie(movie);
                ui->labelImage_r->setScaledContents(true);
                movie->start();
            subw->hide();
        });

         firstPageTime++;
    }else if(firstPageTime==2){

        subw->SetContent("。。。你要再想一想你就会同意了的。。",
                         "://Image/timg-13.gif",true);
        subw->show();
        connect(subw->Button,&QPushButton::clicked,[=]()
        {
            ui->labelShow->setText("再冷静。。再缓一缓。。。");
            ui->yesButton->setText("别说，还真是！");
            ui->noButton->setText("OK！");
             ui->labelImage_r->setPixmap(QPixmap("://Image/IMG_20180627_144813.jpg"));
            subw->hide();
        });
        connect(subw,&SubWidget::close,[=]()
        {
            ui->labelShow->setText("冷静。。缓一缓。。。");
            ui->yesButton->setText("那行！");
            ui->noButton->setText("等我想一想！");
            ui->labelImage_r->setPixmap(QPixmap("://Image/IMG_20180627_144813.jpg"));
            subw->hide();
        });
        firstPageTime++;
    }else if(firstPageTime==3){
        ui->labelShow->setText("这就很好嘛！");
        ui->labelImage_r->setPixmap(QPixmap("://Image/822483909984675464.jpg"));
        ui->yesButton->hide();
        ui->noButton->hide();
        firstPageTime++;
    }

   /* QMovie* movie = new QMovie(":/Image/img-006CqoO6ly1fq4iobtgaog307s0657wh.gif");
    ui->labelShow->setMovie(movie);
    ui->labelShow->setScaledContents(true);
    movie->start();

    ui->yesButton->setText("再想想。。。");
    ui->noButton->setText("点这个没用");*/
}
