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
        QKeyEvent(type, key, modifiers),
        pool(pool)
    {}

private:
    TPool& pool;

};

class input_handler
{

public:
    input_handler()
    {}

};


template<class OBJ, class IH, typename ...Args> 
void operate_obj(OBJ& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler default\n");
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TGame& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    printf("***input_handler GAME %d\n", obj.get_id());

    auto control_id = obj.get_control_id();
    auto control = pool.get_object(control_id);

    operate(*control, ih, pool, offset, type, key, pos);
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TScore& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler SCORE %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler BOARD %d\n", obj.get_id());

}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TTurret& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(pool);
    printf("***input_handler TURRET %d [%d]\n", obj.get_id(), key);

    // FIXME: Temp direct control of weapon
    switch (key)
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
void operate_obj(Console::Objects::TControl& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler CONTROL %d\n", obj.get_id());

    operate_children(obj.get_children(), ih, pool, offset, type, key, pos);
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TButton& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    printf("***input_handler BUTTON %d\n", obj.get_id());

    if (key == obj.get_key())
    {
        printf("\tFOUND!\n");
        auto controlled_obj = pool.get_object(obj.get_controlled_id());

        if (controlled_obj)
        {
            operate(*controlled_obj, ih, pool, offset, type, key, pos);
        }
    }
}


template<class OBJ, class IH, typename ...Args> 
void operate_obj(Console::Objects::TStorage& obj, IH& ih, TPool& pool, QPoint offset, QEvent::Type type, int key, QPointF pos)
{
    Q_UNUSED(obj);
    Q_UNUSED(ih);
    Q_UNUSED(pool);
    printf("***input_handler STORAGE %d\n", obj.get_id());
}


} // namespace Operations
} // namespace Console

#endif // INPUT_HANDLER_H
