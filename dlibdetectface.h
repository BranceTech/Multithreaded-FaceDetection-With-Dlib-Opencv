#ifndef DLIBDETECTFACE_H
#define DLIBDETECTFACE_H

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <iostream>
using namespace dlib;
using namespace cv;


class DetectFacedlib
{
private:
    frontal_face_detector detector = get_frontal_face_detector();
    shape_predictor shape_model;
public:
    DetectFacedlib() ;
    cv::Mat detectfaces(cv::Mat & frame){
        deserialize("/PATH/TO/shape_predictor_68_face_landmarks.dat") >> shape_model;

        array2d<bgr_pixel> dlib_image;
        assign_image(dlib_image, cv_image<bgr_pixel>(frame));

        std::vector<dlib::rectangle> detected_faces = detector(dlib_image);

        int number_of_detected_faces = detected_faces.size();

        cout << "Number of detected faces : " << number_of_detected_faces << endl;

        std::vector<full_object_detection> shapes;

        int rect_x, rect_y, rect_w, rect_h;

        for (int i = 0; i < number_of_detected_faces; i++)
        {
            //full_object_detection shape = shape_model(dlib_image, detected_faces[i]);

            //shapes.push_back(shape);

            rect_x = detected_faces[i].left();
            rect_y = detected_faces[i].top();
            rect_w = detected_faces[i].right() - rect_x;
            rect_h = detected_faces[i].bottom() - rect_y;

            Rect face_rectangle(rect_x, rect_y, rect_w, rect_h);

            cv::rectangle(frame, face_rectangle, Scalar( 0, 255, 0 ), 3, 8, 0);
            /*
            for (int j = 0; j < 68; j++)
            {
                circle(frame, Point(shape.part(j).x(), shape.part(j).y()), 2, Scalar( 0, 0, 255 ), 1, LINE_AA );
            }
            */
        }

       return frame;
    }
};



#endif // DLIBDETECTFACE_H
