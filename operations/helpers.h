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
        printf("***Found GAME\n");
        operate_obj<Console::Objects::TGame&>(static_cast<Console::Objects::TGame&>(obj), op, args...);
        break;
	case Console::Objects::TObject::TYPE_SCORE:
        printf("***Found SCORE\n");
        operate_obj<Console::Objects::TScore&>(static_cast<Console::Objects::TScore&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_BOARD:
        printf("***Found BOARD\n");
        operate_obj<Console::Objects::TBoard&>(static_cast<Console::Objects::TBoard&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_WEAPON:
        printf("***Found WEAPON\n");
        operate_obj<Console::Objects::TWeapon&>(static_cast<Console::Objects::TWeapon&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_TURRET:
        printf("***Found TURRET\n");
        operate_obj<Console::Objects::TTurret&>(static_cast<Console::Objects::TTurret&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_CONTROL:
        printf("***Found CONTROL\n");
        operate_obj<Console::Objects::TControl&>(static_cast<Console::Objects::TControl&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_LEFT_BUTTON:
        printf("***Found LEFT BUTTON\n");
        operate_obj<Console::Objects::TLeft_button&>(static_cast<Console::Objects::TLeft_button&>(obj), op, args...);
        break;
    case Console::Objects::TObject::TYPE_STORAGE:
        printf("***Found STORAGE\n");
        operate_obj<Console::Objects::TStorage&>(static_cast<Console::Objects::TStorage&>(obj), op, args...);
        break;
    default:
        printf("***Found OBJ\n");
        operate_obj<Console::Objects::TObject&>(obj, op, args...);
        break;
    }
}

template<class OP, typename ...Args>
void operate_children(const QList<uint16_t>& children, OP& op, TPool& pool, Args&& ...args)
{
    printf("***operate CHILDREN\n");

    for (auto id : children)
    {
        auto child = pool.get_object(id);
        if (child) operate(*child, op, pool, args...);
    }
}

} // namespace Operations
} // namespace Console

#endif // HELPERS_H
