#include "subwidget.h"
#include <QMovie>
#include<QFont>
#pragma execution_character_set("utf-8")
SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    resize(300,200);

    ContentLabel = new QLabel(this);
    ContentLabel->resize(150,100);
    ContentLabel->move(20,20);
    ContentLabel->setText("fwfwfwf");
    QFont*a=new QFont();
    a->setPointSize(14);
    ContentLabel->setFont(*a);
    ContentLabel->setWordWrap(true);

    PictureLabel = new QLabel(this);
    PictureLabel->resize(100,100);
    PictureLabel->move(180,20);
    PictureLabel->setScaledContents(true);
    PictureLabel->setText("........");

    Button = new QPushButton(this);
    Button->resize(100,70);
    Button->move(150,120);
    Button->setFont(*a);
    Button->setText("^_^");



}

void SubWidget::closeEvent(QCloseEvent *event)
{
    emit close();
    QWidget::closeEvent(event);


}

void SubWidget::SetContent(QString Content, QString ImagePath, bool gif)
{
    ContentLabel->setText(Content);
    if(gif)
    {
        Movie = new QMovie(ImagePath);
        PictureLabel->setMovie(Movie);
        Movie->start();
    }else {
        PictureLabel->setPixmap(QPixmap(ImagePath));

    }



}
