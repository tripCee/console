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
    TTurret(object_id_t id, uint16_t w, uint16_t h, QColor bgc, QColor sc);
    ~TTurret();

    virtual QPixmap get_sprite();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();
    void set_secondary_colour(QColor colour);
    QColor get_secondary_colour();

private:
    QList<object_id_t> children;
    QColor secondary_colour;

};

} // namespace Objects
} // namespace Console

#endif // TTURRET_H
