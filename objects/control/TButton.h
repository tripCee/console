#ifndef TBUTTON_H
#define TBUTTON_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TButton : public TObject
{
    //Q_OBJECT

public:
    TButton();
    TButton(object_id_t id, 
            uint16_t w, 
            uint16_t h, 
            uint16_t bw, 
            QColor bgc, 
            QColor fgc, 
            Qt::Key k, 
            object_id_t cid, 
            type_t object_type = TObject::TYPE_WEAPON);
    ~TButton();

    QColor get_foreground_colour();
    Qt::Key get_key();
    void set_controlled_id(object_id_t cid);
    object_id_t get_controlled_id();
    void set_is_pressed(bool pressed);
    bool get_is_pressed();

private:
    QColor foreground_colour;
    Qt::Key key;
    object_id_t controlled_id;
    bool is_pressed;
};

} // namespace Objects
} // namespace Console

#endif // TBUTTON_H
