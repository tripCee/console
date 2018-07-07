#ifndef TWEAPON_H
#define TWEAPON_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TWeapon : public TObject
{
    //Q_OBJECT

public:
    TWeapon();
    TWeapon(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, type_t object_type = TObject::TYPE_WEAPON);
    ~TWeapon();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();

private:
    //grid
    QList<object_id_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TWEAPON_H
