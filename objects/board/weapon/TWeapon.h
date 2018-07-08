#ifndef TWEAPON_H
#define TWEAPON_H

#include "objects/TObject.h"

namespace Console {
namespace Objects {

class TWeapon : public TObject
{
    //Q_OBJECT

public:
    TWeapon();
    TWeapon(object_id_t id, uint16_t w, uint16_t h, QColor bgc, type_t object_type = TObject::TYPE_WEAPON);
    ~TWeapon();

    virtual QPixmap get_sprite() = 0;

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();
    void set_speed(uint8_t s);
    uint8_t get_speed();
    void set_max_speed(uint8_t ms);
    uint8_t get_max_speed();
    void set_rotate_speed(uint8_t rs);
    uint8_t get_rotate_speed();
    void rotate_cw();
    void rotate_acw();
    void set_direction(uint16_t d);
    uint16_t get_direction();
    void set_gun_power(uint8_t gp);
    uint8_t get_gun_power();
    void set_gun_rotate_speed(uint8_t grs);
    uint8_t get_gun_rotate_speed();
    void rotate_gun_cw();
    void rotate_gun_acw();
    void set_gun_direction(uint16_t gd);
    uint16_t get_gun_direction();

private:
    QList<object_id_t> children;
    uint8_t speed;
    uint8_t max_speed;
    uint8_t rotate_speed;
    uint16_t direction;
    uint8_t gun_power;
    uint8_t gun_rotate_speed;
    uint16_t gun_direction;
};

} // namespace Objects
} // namespace Console

#endif // TWEAPON_H
