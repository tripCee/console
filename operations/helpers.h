#ifndef HELPERS_H
#define HELPERS_H

#include "operations/painter.h"
#include "objects/All_objects.h"

namespace Console {
namespace Operations {

template<class OP, typename ...Args> 
void operate(Console::Objects::TObject& obj, OP& op, Args&& ...args)
{
    switch (obj.get_type())
    {
	case Console::Objects::TObject::TYPE_GAME:
        operate_obj<Console::Objects::TGame&>(static_cast<Console::Objects::TGame&>(obj), op, args...);
        break;
	case Console::Objects::TObject::TYPE_SCORE:
        operate_obj<Console::Objects::TScore&>(static_cast<Console::Objects::TScore&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_BOARD:
        operate_obj<Console::Objects::TBoard&>(static_cast<Console::Objects::TBoard&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_AMMUNITION:
        operate_obj<Console::Objects::TAmmunition&>(static_cast<Console::Objects::TAmmunition&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_BULLET:
        operate_obj<Console::Objects::TBullet&>(static_cast<Console::Objects::TBullet&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_WEAPON:
        operate_obj<Console::Objects::TWeapon&>(static_cast<Console::Objects::TWeapon&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_TURRET:
        operate_obj<Console::Objects::TTurret&>(static_cast<Console::Objects::TTurret&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_CONTROL:
        operate_obj<Console::Objects::TControl&>(static_cast<Console::Objects::TControl&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_BUTTON:
        operate_obj<Console::Objects::TButton&>(static_cast<Console::Objects::TButton&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_LEFT_BUTTON:
        operate_obj<Console::Objects::TLeft_button&>(static_cast<Console::Objects::TLeft_button&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_RIGHT_BUTTON:
        operate_obj<Console::Objects::TRight_button&>(static_cast<Console::Objects::TRight_button&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_FIRE_BUTTON:
        operate_obj<Console::Objects::TFire_button&>(static_cast<Console::Objects::TFire_button&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_STORAGE:
        operate_obj<Console::Objects::TStorage&>(static_cast<Console::Objects::TStorage&>(obj), op, args...);
        break;
    default:
        operate_obj<Console::Objects::TObject&>(obj, op, args...);
        break;
    }
}

template<class OP, typename ...Args>
void operate_children(const QMap<object_id_t, QPoint>& children, OP& op, TPool& pool, QPoint offset, Args&& ...args)
{
    QMapIterator<object_id_t, QPoint> i(children);
    while (i.hasNext())
    {
        i.next();
        auto child = pool.get_object(i.key());
        if (child) operate(*child, op, pool, offset + i.value(), args...);
    }
}

} // namespace Operations
} // namespace Console

#endif // HELPERS_H
