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

class key_event : public QKeyEvent
{
public:
    key_event(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, TPool& pool):
        QKeyEvent(type, key, modifiers)
    {}


};

class input_handler
{

public:
    input_handler(QEvent::Type type, int key, QPointF pos):
        type(type), 
        key(key), 
        pos(pos)
    {}

    QEvent::Type type;
    int key;
    QPointF pos;
};


template<class OBJ, class IH, typename ...Args> 
void operate_obj(OBJ& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler default\n");
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TGame& obj, IH& ih, TPool& pool)
{
    printf("***input_handler GAME %d\n", obj.get_id());

    // FIXME: Temp direct control of weapon
    auto weapon_id = obj.get_weapon_id();
    auto weapon = pool.get_object(weapon_id);

    operate(*weapon, ih, pool);

    // auto control_id = obj.get_control_id();
    // auto control = pool.get_object(control_id);

    // operate(*control, ih, pool);
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TScore& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler SCORE %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler BOARD %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TTurret& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(pool);
    printf("***input_handler TURRET %d [%d]\n", obj.get_id(), ih.key);

    // FIXME: Temp direct control of weapon
    switch (ih.key)
    {
        case Qt::Key_Left:
            obj.rotate_gun_acw();
            break;
        case Qt::Key_Right:
            obj.rotate_gun_cw();
            break;
        default:
            break;
    }
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TControl& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler CONTROL %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TStorage& obj, IH& ih, TPool& pool)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler STORAGE %d\n", obj.get_id());
}


} // namespace Operations
} // namespace Console

#endif // INPUT_HANDLER_H
