#ifndef TPOOL_H
#define TPOOL_H

#include "objects/TObject.h"
#include "objects/TGame.h"

#include <QMap>

class TPool : public QObject
{
    Q_OBJECT

public:
    TPool();
    ~TPool();

    void add_game(uint16_t id, Console::Objects::TGame* game);
    Console::Objects::TGame* get_game();

    void add_object(uint16_t id, Console::Objects::TObject* object);
    Console::Objects::TObject* get_object(uint16_t id);

    const QMap<uint16_t, Console::Objects::TObject*>& get_objects();

private:
    uint16_t game_oid;
    QMap<uint16_t, Console::Objects::TObject*> objects;
};

#endif // TPOOL_H
