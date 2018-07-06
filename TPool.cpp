#include "TPool.h"

TPool::TPool(): 
    QObject(),
    game_oid(0),
    objects()
{
}


TPool::~TPool()
{
}

void TPool::add_game(uint16_t id, Console::Objects::TGame* game)
{
    game_oid = id;
    objects.insert(id, game);
}

Console::Objects::TGame* TPool::get_game()
{ 
    return static_cast<Console::Objects::TGame*>(get_object(game_oid));
}

void TPool::add_object(uint16_t id, Console::Objects::TObject* object)
{
    objects.insert(id, object);
}

Console::Objects::TObject* TPool::get_object(uint16_t id)
{
    QMap<uint16_t, Console::Objects::TObject*>::iterator i = objects.find(id);
    if (i == objects.end()) return nullptr;
    
    return i.value();
}

const QMap<uint16_t, Console::Objects::TObject*>& TPool::get_objects()
{
    return objects;
}

