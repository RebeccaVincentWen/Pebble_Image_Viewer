
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
#include <QToolBar>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QQuickWidget>
#include <QQmlContext>

#include "mainwindow.h"
#include "image_Processing.hpp"
#include "customization.hpp"

#define EndofHistoryCache "EoHC"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget app_mainWindow;
    app_mainWindow.setWindowTitle("Pebble (Prototype Version 2)");
    app_mainWindow.resize(1024, 768);

    QVBoxLayout app_mainLayout;
    QLabel app_imageShowingLabel;
    QToolBar app_toolBar;

    app_mainWindow.show();

    return a.exec();
}
