
#include "detectfacecv.h"
#include "mythread.h"
#include <QtCore>
#include <QThread>
#include <QImage>
#include <QDebug>
#include <string>
//#include "dlibdetectface.h"

//opencvmodules



using namespace cv;
using namespace std;
using namespace cv::dnn;


CaptureThread::CaptureThread(int labelId):
    QThread()
{
    //this->source=src;
    //++cameraId;
    cameraId=labelId;
    qDebug()<<"temporary inapplicable"<<endl;
    qDebug()<<"Memory address for cameraId"<<cameraId<<endl;
}

bool CaptureThread::connectToCamera()
{
    // Open camera
    qDebug() << "MARK 2";
     //qDebug()<<"Memory address"<<sharedBuffer<<endl;
    //qDebug()<<"Memory address for cameraId"<<cameraId<<endl;

    bool camOpenResult= cap.open(source);
    qDebug()<<"after cap open"<<endl;
    // Set resolution
    if(width != -1)
        cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
    if(height != -1)
        cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);
    // Return result
    qDebug()<<"bool mode"<<camOpenResult<<endl;
    return camOpenResult;
}

void CaptureThread::run(){
    qDebug()<<"in runmode"<<endl;
    //CREATE FACE DETECTOR OBJECT
   DetectFaceCv *detector=new DetectFaceCv();


   if(connectToCamera()){
       qDebug()<<"streaming started ........."<<endl;

       while(1){
            qDebug()<<"in while loop................."<<endl;


           qDebug()<<"grabbed ................."<<endl;
           cap>>grabbedFrame;
           if(!cap.read(grabbedFrame)){
               qDebug()<<"No more frames ................."<<endl;

               break;
           }
           //cap.retrieve(grabbedFrame);
           if (!cap.grab())
               continue;
           detector->detectFaceOpenCVDNN(grabbedFrame);

           //sharedBuffer->getByDeviceNumber(cameraId)->add(grabbedFrame, dropFrameIfBufferFull);

           img = mat8ToImage(grabbedFrame);
           qDebug()<<"grabbed image................."<<img<<endl;

           emit returntomain(img);

           // Retrieve frame

        }

    }

  }
QImage CaptureThread::mat8ToImage(const cv::Mat &mat)
{
    switch (mat.type()) {
    case CV_8UC1:
    {
        qDebug()<<"CV_8UC1"<<endl;
        QVector<QRgb> ct;
        for (int i = 0; i < 256; ++i)
            ct.append(qRgb(i, i, i));
        QImage result(mat.data, mat.cols, mat.rows, (int) mat.step, QImage::Format_Indexed8);
        result.setColorTable(ct);
        return result.copy();
    }
    case CV_8UC3:
    {
        qDebug()<<"CV_8UC3"<<endl;
        cv::Mat tmp;
        cvtColor(mat, tmp, CV_BGR2BGRA);
        return mat8ToImage(tmp);
    }
    case CV_8UC4:
    {   qDebug()<<"CV_8UC4"<<endl;
        QImage result(mat.data, mat.cols, mat.rows, (int) mat.step, QImage::Format_RGB32);
        return result.rgbSwapped();
    }
    default:
        qWarning("Unhandled Mat format %d", mat.type());
        return QImage();
    }
}
