
#include <QApplication>
#include <QLabel>
#include <QWindow>
#include <QLayout>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLineEdit>

#include "mainwindow.h"
#include "image_Processing.hpp"
#include "logic_handler.hpp"

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
    QPushButton button_Nextpage, button_Frontpage, ScanFolderButton;

    //define the display window of the image
    QLabel imageDisplayLabel;
    QLineEdit InputTheFilePath;
    
    File_Processing::FileProcessor fileProcessor;
    std::vector<std::string> filePathSet;
    std::string fileExtension = ".jpg";

    app_logic_handler::logicHandler_base handler;

    button_Frontpage.setText("<");
    button_Nextpage.setText(">");

    ScanFolderButton.setText("Scan For Images");

    application_Top_Tool_Bar.addWidget(&button_Frontpage);
    application_Top_Tool_Bar.addWidget(&button_Nextpage);
    application_Top_Tool_Bar.addWidget(&InputTheFilePath);
    application_Top_Tool_Bar.addWidget(&ScanFolderButton);

    QObject::connect(&ScanFolderButton, &QPushButton::clicked, [&](){
        handler.button_ScanFolder_reaction_handler(fileExtension, 
            InputTheFilePath, filePathSet, fileProcessor);
    });

    application_generalLayout.addLayout(&application_Top_Tool_Bar);
    application_generalLayout.addWidget(&imageDisplayLabel);
    application_generalLayout.setAlignment(Qt::AlignTop);

    app_mainWindow.setLayout(&application_generalLayout);
    app_mainWindow.show();

    return a.exec();
}
