#ifndef TTURRET_H
#define TTURRET_H

#include "TWeapon.h"

#include <QList>

namespace Console {
namespace Objects {

class TTurret : public TWeapon
{
    //Q_OBJECT

public:
    TTurret();
    TTurret(object_id_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TTurret();

    virtual QPixmap get_sprite();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();

private:
    QList<object_id_t> children;

};

} // namespace Objects
} // namespace Console

#endif // TTURRET_H
