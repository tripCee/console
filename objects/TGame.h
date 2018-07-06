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
    TGame(uint16_t id, uint16_t w, uint16_t h, QColor bgc, uint16_t current_level);
    ~TGame();

    void set_score_id(uint16_t id);
    uint16_t get_score_id();
    void add_child(uint16_t cid);
    const QList<uint16_t>& get_children();
    void set_current_level(uint16_t bs);
    uint16_t get_current_level();

private:
    uint16_t score_id;
    QList<uint16_t> children;
    uint16_t current_level;
};

} // namespace Objects
} // namespace Console

#endif // TGAME_H
