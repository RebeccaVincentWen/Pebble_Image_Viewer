
#include "customization.hpp"

Generic_PushButton::Generic_PushButton(QWidget* parent){}

void Generic_PushButton::paintEvent(QPaintEvent *event){
    QPainter buttonColorPainter(this);
    buttonColorPainter.setRenderHint(QPainter::Antialiasing);

    if(underMouse()){
        defaultBackgroundColor = Qt::gray;
    }
    if(!underMouse()){
        defaultBackgroundColor = QColor::fromRgb(167, 193, 217);
    }

    buttonColorPainter.setBackground(defaultBackgroundColor);
    buttonColorPainter.setPen(Qt::NoPen);
    buttonColorPainter.drawRect(rect());
    buttonColorPainter.fillRect(rect(), defaultBackgroundColor);

    buttonColorPainter.setPen(Qt::white);
    buttonColorPainter.drawText(rect(), Qt::AlignCenter,text());
}

void Generic_PushButton::enterEvent(QEnterEvent *event){update();}

void Generic_PushButton::leaveEvent(QEvent* event){update();}