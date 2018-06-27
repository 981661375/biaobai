#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
signals:
    void close();
public slots:

public:
    void SetContent(QString Content,QString ImagePath,bool gif);

    QLabel* ContentLabel;
    QLabel* PictureLabel;
    class QMovie* Movie;
      QString Content;
      QPushButton* Button;
};

#endif // SUBWIDGET_H
