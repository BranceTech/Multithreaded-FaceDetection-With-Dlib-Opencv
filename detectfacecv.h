#ifndef DETECTFACECV_H
#define DETECTFACECV_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace std;
using namespace cv::dnn;


class DetectFaceCv
{
public:
    DetectFaceCv();
    void detectFaceOpenCVDNN(Mat &frameOpenCVDNN);
private:
    const size_t inWidth = 300;
    const size_t inHeight = 300;
    const double inScaleFactor = 1.0;
    const float confidenceThreshold = 0.7;

    #define CAFFE

    const std::string caffeWeightFile = "/home/techbridge/Downloads/res10_300x300_ssd_iter_140000_fp16.caffemodel";
    const std::string caffeConfigFile = "/home/techbridge/Models/deploy.prototxt.txt";


    const std::string tensorflowConfigFile = "opencv_face_detector.pbtxt";
    const std::string tensorflowWeightFile = "opencv_face_detector_uint8.pb";

    #ifdef CAFFE
      Net net = cv::dnn::readNetFromCaffe(caffeConfigFile, caffeWeightFile);
    #else
      Net net = cv::dnn::readNetFromTensorflow(tensorflowWeightFile, tensorflowConfigFile);
    #endif

};

#endif // DETECTFACECV_H
