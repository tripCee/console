#ifndef TRIGHT_BUTTON_H
#define TRIGHT_BUTTON_H

#include "objects/control/TButton.h"

#include <QList>

namespace Console {
namespace Objects {

class TRight_button : public TButton
{
    //Q_OBJECT

public:
    TRight_button();
    TRight_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid);
    ~TRight_button();

private:
};

} // namespace Objects
} // namespace Console

#endif // TRIGHT_BUTTON_H
