
#include <QApplication>
#include <QLabel>
#include <QWindow>
#include <QLayout>
#include <QWidget>

#include "mainwindow.h"
#include "image_Processing.hpp"
#include "logic_handler.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget app_mainWindow;

    QVBoxLayout app_generalLayout;

    app_mainWindow.setLayout(&app_generalLayout);
    app_mainWindow.show();

    return a.exec();
}
