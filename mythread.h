#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/opencv.hpp>
#include <QtCore/QThread>
#include <opencv2/dnn.hpp>
#include <string>
#include <QImage>

using namespace cv;
using namespace std;

class CaptureThread:public QThread
{Q_OBJECT
public:
    CaptureThread(int labelId);
    //int source;
    string source;
    //string source;
    //not neccesary
    bool dropFrameIfBufferFull=false;
    QImage mat8ToImage(const cv::Mat &mat);
    bool connectToCamera();

    //void set_source();

private:
    int cameraId;

    Mat RGBframe;
    VideoCapture cap;
    Mat grabbedFrame;

    volatile bool doStop;
    int width=400;
    int height=500;
    bool isOpen;
    QImage img;


signals:
    void returntomain(const QImage &image);
protected:
     void run();

};

#endif // MYTHREAD_H
