#ifndef TLEFT_BUTTON_H
#define TLEFT_BUTTON_H

#include "objects/control/TButton.h"

#include <QList>

namespace Console {
namespace Objects {

class TLeft_button : public TButton
{
    //Q_OBJECT

public:
    TLeft_button();
    TLeft_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid);
    ~TLeft_button();

private:
};

} // namespace Objects
} // namespace Console

#endif // TLEFT_BUTTON_H
