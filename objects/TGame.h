#ifndef TGAME_H
#define TGAME_H

#include "objects/TObject.h"
#include "objects/score/TScore.h"

#include <QList>

namespace Console {
namespace Objects {

class TGame : public TObject
{
    //Q_OBJECT

public:
    //TGame();
    TGame(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, uint16_t current_level);
    ~TGame();

    void set_score_id(object_id_t id);
    object_id_t get_score_id();
    void set_control_id(object_id_t id);
    object_id_t get_control_id();
    void set_storage_id(object_id_t id);
    object_id_t get_storage_id();
    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();
    object_id_t get_current_board_id();
    void set_current_level(uint16_t bs);
    uint16_t get_current_level();

private:
    object_id_t score_id;
    object_id_t control_id;
    object_id_t storage_id;
    QList<object_id_t> children;
    uint16_t current_level;
};

} // namespace Objects
} // namespace Console

#endif // TGAME_H
