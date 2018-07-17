#ifndef TBOARD_H
#define TBOARD_H

#include "objects/TObject.h"

#include <QMap>

namespace Console {
namespace Objects {

class TBoard : public TObject
{

public:
    TBoard();
    TBoard(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, uint16_t block_size);
    ~TBoard();

    void add_child(object_id_t cid, QPoint pos);
    const QMap<object_id_t, QPoint>& get_children();
    void set_weapon_id(object_id_t w);
    object_id_t get_weapon_id();
    void set_block_size(uint16_t bs);
    uint16_t get_block_size();

private:
    QMap<object_id_t, QPoint> children;
    object_id_t weapon_id;
    uint16_t block_size;
};

} // namespace Objects
} // namespace Console

#endif // TBOARD_H
