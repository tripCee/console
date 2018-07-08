#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "TPool.h"
#include "objects/All_objects.h"

#include <QKeyEvent>
#include <QImage>
#include <QPoint>
#include <QRect>

namespace Console {
namespace Operations {

class input_handler : public QKeyEvent
{

public:
    input_handler(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers):
        QKeyEvent(type, key, modifiers)
    {}

};


template<class OBJ, class IH, typename ...Args> 
void operate_obj(OBJ& obj, IH& ih, TPool& pool)
{
    printf("***input_handler default\n");
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TGame& obj, IH& ih, TPool& pool)
{
    printf("***input_handler GAME %d\n", obj.get_id());
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TScore& obj, IH& ih, TPool& pool)
{
    printf("***input_handler SCORE %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, IH& ih, TPool& pool)
{
    printf("***input_handler BOARD %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TTurret& obj, IH& ih, TPool& pool)
{
    printf("***input_handler TURRET %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TControl& obj, IH& ih, TPool& pool)
{
    printf("***input_handler CONTROL %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TStorage& obj, IH& ih, TPool& pool)
{
    printf("***input_handler STORAGE %d\n", obj.get_id());
}


} // namespace Operations
} // namespace Console

#endif // INPUT_HANDLER_H
