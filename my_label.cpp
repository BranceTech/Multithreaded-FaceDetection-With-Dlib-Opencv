#include "my_label.h"
using namespace  std;

CustomLabel::CustomLabel(QWidget *parent):
    QLabel(parent)


{
    this->setText("Camera connected. Waiting...");
    ++this->labelId;

    deamon = new CaptureThread(labelId);

    QObject::connect(deamon, SIGNAL(returntomain(QImage)),
    this, SLOT(updatelabelwithframe(QImage)));

}



void CustomLabel::startdeamon(std::string src){
    /*
     device;
    try{
        device=src.toInt();
    }
    catch(...){

        cerr << "ellipsis catch" << endl;


    }
    */
    deamon->source=src;

  // deamon = new CaptureThread(labelId);

   //this->setText("Camera connected. Waiting...");
   if (deamon->connectToCamera()){

        deamon->start();
       // processingThread->start((QThread::Priority)deamonPrio);
    }
    qDebug()<<"false";
}
void CustomLabel::updatelabelwithframe(QImage frame){
    qDebug()<<"getting frame"<<endl;
    this->setPixmap(QPixmap::fromImage(frame).scaled(this->size(),
                                               Qt::KeepAspectRatio, Qt::FastTransformation));

}

CustomLabel::~CustomLabel(){
    delete deamon;
}
