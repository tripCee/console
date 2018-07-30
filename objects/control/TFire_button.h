#ifndef TFIRE_BUTTON_H
#define TFIRE_BUTTON_H

#include "objects/control/TButton.h"

#include <QList>

namespace Console {
namespace Objects {

class TFire_button : public TButton
{
    //Q_OBJECT

public:
    TFire_button();
    TFire_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid);
    ~TFire_button();

private:
};

} // namespace Objects
} // namespace Console

#endif // TFIRE_BUTTON_H
