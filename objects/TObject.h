#ifndef TOBJECT_H
#define TOBJECT_H

#include <QColor>
#include <QPixmap>

typedef uint16_t object_id_t;

namespace Console {
namespace Objects {

class TObject
{
public:
    enum type_t {
        TYPE_GAME = 0,
        TYPE_SCORE = 1,
        TYPE_BOARD = 2,
        TYPE_CONTROL = 3,
        TYPE_STORAGE = 4,

        // Weapons
        TYPE_WEAPON = 5,
        TYPE_TURRET = 50,

        // Ammunition
        TYPE_AMMUNITION = 6,
        TYPE_BULLET = 60
    };

    TObject();
    TObject(type_t object_type, object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc);
    ~TObject();

    type_t get_type();
    void set_id(uint16_t id);
    object_id_t get_id();
    void set_size(uint16_t w, uint16_t h);
    void set_width(uint16_t w);
    void set_height(uint16_t h);
    void set_border_width(uint16_t bw);
    uint16_t get_width();
    uint16_t get_height();
    uint16_t get_border_width();
    void set_bg_colour(QColor bgc);
    QColor get_bg_colour();

private:
    type_t type;
    object_id_t id;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    QColor bg_colour;
};

} // namespace Objects
} // namespace Console

#endif // TOBJECT_H
