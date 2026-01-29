//this file mainly handles the logic behind
#pragma once

#include <QObject>
#include <QLabel>
#include <QLineEdit>

#include <deque>

#include "image_Processing.hpp"
#include "file_Processing.hpp"

namespace app_logic_handler{

class logicHandler_base: public QObject{
    Q_OBJECT;//make the slot to function normally

    public slots:
    //here put the basic handler here
    void button_Previousimage_reaction_handler(File_Processing::FileProcessor& fileProcessor, 
        image_Processor& imageProcessor, QLabel& labelObject){
        std::deque<std::string> tempDeque = fileProcessor.GettheDeque();
        imageProcessor.readImage_Through_Filepath(tempDeque[tempDeque.size() - 2], labelObject);
    }

    void button_Nextimage_reaction_handler(){}

    void button_ScanFolder_reaction_handler(std::string& fileExtension, 
        QLineEdit& lineEdit, 
        std::deque<std::string>& filePathSet, File_Processing::FileProcessor& fileProcessor){
            std::string tempUserInput = lineEdit.text().toStdString();
            fileProcessor.selectAndScanFolder(fileExtension, tempUserInput, filePathSet);
        }
};

};