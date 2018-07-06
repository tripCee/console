#ifndef TOBJECT_H
#define TOBJECT_H

//#include <QObject>
#include <QColor>
#include <QPixmap>

namespace Console {
namespace Objects {

class TObject //: public QObject
{
    //Q_OBJECT

public:
    enum type_t {
        TYPE_GAME = 0,
        TYPE_SCORE = 1,
        TYPE_BOARD = 2
    };

    TObject();
    TObject(type_t object_type, uint16_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TObject();

    type_t get_type();
    void set_id(uint16_t id);
    uint16_t get_id();
    void set_size(uint16_t w, uint16_t h);
    void set_width(uint16_t w);
    void set_height(uint16_t h);
    uint16_t get_width();
    uint16_t get_height();
    void set_bg_colour(QColor bgc);
    QColor get_bg_colour();

private:
    type_t type;
    uint16_t id;
    uint16_t width;
    uint16_t height;
    QColor bg_colour;
};

} // namespace Objects
} // namespace Console

#endif // TOBJECT_H
