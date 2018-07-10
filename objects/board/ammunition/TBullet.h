#ifndef TBULLET_H
#define TBULLET_H

#include "TAmmunition.h"

#include <QList>

namespace Console {
namespace Objects {

class TBullet : public TAmmunition
{

public:
    TBullet();
    TBullet(object_id_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TBullet();

    virtual QPixmap get_sprite();

private:

};

} // namespace Objects
} // namespace Console

#endif // TBULLET_H
