//image_Processing header file
//this header file aimed to process the image using the Magick++ library
#pragma once

#include <opencv2/opencv.hpp>

#include <QImage>
#include <QPixmap>
#include <QLabel>

#include <memory>

class image_Processor{
private:

public:

    image_Processor();
    ~image_Processor();

    void MoveToCurrentPosition();
    QImage cvMatToQImage(const cv::Mat& mat);
    void readImage_Through_Filepath(std::string& image_path, QLabel& labelObject);
};


