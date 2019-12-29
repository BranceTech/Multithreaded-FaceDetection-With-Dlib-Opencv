#ifndef MY_LABEL_H
#define MY_LABEL_H
#include <QLabel>
#include <QDebug>
#include "mythread.h"
#include "string"

class CustomLabel:public QLabel
{

    Q_OBJECT
public:
    CustomLabel(QWidget *parent);

    ~CustomLabel();
    void startdeamon(std::string src);


private:

    int labelId;
    CaptureThread *deamon;


    //void setGeometry(const QRect &);
    int deamonPrio=3;
protected:

signals:

private slots:
    void updatelabelwithframe(QImage frame);

public slots:


};


#endif // MY_LABEL_H
