
#include <QApplication>
#include <QLabel>
#include <QWindow>
#include <QLayout>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLineEdit>
#include <QMenu>
#include <QColor>

#include "mainwindow.h"
#include "image_Processing.hpp"
#include "logic_handler.hpp"
#include "customization.hpp"

#define EndofHistoryCache "EoHC"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget app_mainWindow;
    app_mainWindow.setWindowTitle("Pebble (Prototype) Version 1");

    //define the layout of the window
    QVBoxLayout application_generalLayout;
    QHBoxLayout application_Top_Tool_Bar;

    //define the control elements on the screen
    Generic_PushButton button_Nextpage, button_Frontpage, ScanFolderButton, imageSelectionButton;
    QMenu menu_ImageSelection, menu_extensionNameSelection;
    Generic_PushButton button_extensionNameSelection, button_ClearFilePathSet;

    button_extensionNameSelection.setMouseTracking(true);
    button_extensionNameSelection.setText("Extension");

    imageSelectionButton.setText("Image Selection");

    //define the display window of the image
    QLabel imageDisplayLabel;
    QLineEdit InputTheFilePath;
    
    File_Processing::FileProcessor fileProcessor;
    std::deque<std::string> filePathSet = std::deque<std::string>();
    std::string fileExtension = ".jpg";
    std::vector<std::string> fileExtensionNames = {".png", ".jpg", ".jpeg"};

    int16_t temporary_index = 0;

    for(std::string item: fileExtensionNames){
        menu_extensionNameSelection.addAction(QString::fromStdString(item))->setData(temporary_index);
        temporary_index ++;
    }

    button_extensionNameSelection.setMenu(&menu_extensionNameSelection);
    QObject::connect(&menu_extensionNameSelection, &QMenu::triggered, [&](QAction* action){
        fileExtension = fileExtensionNames[action->data().toInt()];
    });

    image_Processor imageProcessor;

    app_logic_handler::logicHandler_base handler;

    button_Frontpage.setText("<");
    button_Nextpage.setText(">");

    ScanFolderButton.setText("Scan For Images");
    button_ClearFilePathSet.setText(QString::fromStdString("Clear List"));

    //application_Top_Tool_Bar.addWidget(&button_Frontpage);
    //application_Top_Tool_Bar.addWidget(&button_Nextpage);
    application_Top_Tool_Bar.addWidget(&InputTheFilePath);
    application_Top_Tool_Bar.addWidget(&ScanFolderButton);
    application_Top_Tool_Bar.addWidget(&button_extensionNameSelection);
    application_Top_Tool_Bar.addWidget(&button_ClearFilePathSet);

    std::vector<QAction*> tempAction;

    QObject::connect(&ScanFolderButton, &QPushButton::clicked, [&](){
        filePathSet.clear();
        handler.button_ScanFolder_reaction_handler(fileExtension, 
            InputTheFilePath, filePathSet, fileProcessor);
            int16_t indexIntheDeque = 0;
            fileProcessor.ClearOriginalCache();
            bool checkresult = false;
            for(std::string item: filePathSet){
                fileProcessor.temporarilyStoreHistory(item, filePathSet);
                //tempAction.emplace_back(menu_ImageSelection.addAction(QString::fromStdString(item)));
                //tempAction[indexIntheDeque]->setData(indexIntheDeque);

                for(QAction* action: menu_ImageSelection.actions()){
                    if((*action).text().toStdString() == item){checkresult = true;}
                }

                if(!checkresult){
                    tempAction.emplace_back(menu_ImageSelection.addAction(QString::fromStdString(item)));
                    tempAction[indexIntheDeque]->setData(indexIntheDeque);
                }
                checkresult = false;

                indexIntheDeque++;
            }
            //fileProcessor.DebugOutput(filePathSet);
    });

    QObject::connect(&menu_ImageSelection, &QMenu::triggered, [&](QAction* action){
        if (action) {
        int image_pathIndex = action->data().toInt();
        
        // Safety check to ensure index is within the deque's bounds
        if (image_pathIndex >= 0 && image_pathIndex < fileProcessor.GettheDeque().size()) {
            imageProcessor.readImage_Through_Filepath(
                fileProcessor.GettheDeque()[image_pathIndex], imageDisplayLabel);
        }
    }
    });

    QObject::connect(&button_ClearFilePathSet, &QPushButton::clicked, [&](){
        filePathSet.clear();
        fileProcessor.ClearOriginalCache();
    });

    imageDisplayLabel.setFixedSize(800, 600);
    imageDisplayLabel.setScaledContents(true);

    imageSelectionButton.setMenu(&menu_ImageSelection);

    application_generalLayout.addLayout(&application_Top_Tool_Bar);
    application_generalLayout.addWidget(&imageSelectionButton);
    application_generalLayout.addWidget(&imageDisplayLabel);
    application_generalLayout.setAlignment(Qt::AlignTop);

    app_mainWindow.setLayout(&application_generalLayout);
    app_mainWindow.show();

    return a.exec();
}
