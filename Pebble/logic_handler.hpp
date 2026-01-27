//this file mainly handles the logic behind
#pragma once

#include <QObject>

#include "image_Processing.hpp"
#include "file_Processing.hpp"

namespace app_logic_handler{

class logicHandler_base: public QObject{
    Q_OBJECT;//make the slot to function normally

    public slots:
    //here put the basic handler here
    void button_Previousimage_reaction_handler(){}

    void button_Nextimage_reaction_handler(){}
};

};