
#include "image_Processing.hpp"

void image_Processor::readImage_Through_Filepath(std::string& image_path, QLabel& labelObject){
    cv::Mat imageInput = cv::imread(image_path);
    if(imageInput.empty() == true){return;}

    cv::cvtColor(imageInput, imageInput, cv::COLOR_BGR2RGB);

    QImage finalOutputImage = cvMatToQImage(imageInput);
    labelObject.setPixmap(QPixmap::fromImage(finalOutputImage));
}

QImage image_Processor::cvMatToQImage(const cv::Mat& mat) {
    switch (mat.type()) {
        // 8-bit, 3-channel (BGR)
        case CV_8UC3: {
            QImage qimg(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_BGR888);
            return qimg.rgbSwapped().copy(); // Convert BGR to RGB
        }
        // 8-bit, 1-channel (Grayscale)
        case CV_8UC1: {
            return QImage(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_Grayscale8).copy();
        }
        default:
            return QImage();
    }
}