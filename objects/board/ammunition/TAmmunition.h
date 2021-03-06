#ifndef TAMMUNITION_H
#define TAMMUNITION_H

#include "objects/TObject.h"

namespace Console {
namespace Objects {

class TAmmunition : public TObject
{
    //Q_OBJECT

public:
    TAmmunition();
    TAmmunition(object_id_t id, uint16_t w, uint16_t h, QColor bgc, type_t object_type = TObject::TYPE_AMMUNITION);
    ~TAmmunition();

    virtual QPixmap get_sprite() = 0;

    QPointF get_pos();
    void set_speed(uint8_t s);
    uint8_t get_speed();
    void set_max_speed(uint8_t ms);
    uint8_t get_max_speed();
    void set_power(uint8_t p);
    uint8_t get_power();
    void set_direction(uint16_t d);
    uint16_t get_direction();
    void set_fired(bool f);
    bool get_fired();

    virtual void update() override;

private:
    QPointF pos;
    uint8_t speed;
    uint8_t max_speed;
    uint8_t power;
    uint16_t direction;
    bool fired;
};

} // namespace Objects
} // namespace Console

#endif // TAMMUNITION_H
