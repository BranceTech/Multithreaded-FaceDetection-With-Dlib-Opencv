#include "detectfacecv.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>


const cv::Scalar meanVal(104.0, 177.0, 123.0);


DetectFaceCv::DetectFaceCv()
{

    const std::string caffeConfigFile = "/home/techbridge/collins/My cpp stuff/collo/deploy.prototxt";
    const std::string caffeWeightFile = "/home/techbridge/collins/My cpp stuff/collo/res10_300x300_ssd_iter_140000_fp16.caffemodel";

    cv::dnn::Net net = cv::dnn::readNetFromCaffe(caffeConfigFile,caffeWeightFile);
}

void DetectFaceCv::detectFaceOpenCVDNN(Mat &frameOpenCVDNN){

        int frameHeight = frameOpenCVDNN.rows;
        int frameWidth = frameOpenCVDNN.cols;

        //resize(frameOpenCVDNN, frameOpenCVDNN, Size(300, 300));


        #ifdef CAFFE
            cv::Mat inputBlob = cv::dnn::blobFromImage(frameOpenCVDNN, inScaleFactor, cv::Size(inWidth, inHeight), meanVal, false, false);
        #else
            cv::Mat inputBlob = cv::dnn::blobFromImage(frameOpenCVDNN, inScaleFactor, cv::Size(inWidth, inHeight), meanVal, true, false);
        #endif

        net.setInput(inputBlob, "data");
        cv::Mat detection = net.forward("detection_out");

        cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

        for(int i = 0; i < detectionMat.rows; i++)
        {
            float confidence = detectionMat.at<float>(i, 2);
            cout << confidence << endl;

            if(confidence > confidenceThreshold)
            {

                int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frameWidth);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frameHeight);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frameWidth);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frameHeight);

                cv::rectangle(frameOpenCVDNN, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0),2, 4);
            }
        }

    }

