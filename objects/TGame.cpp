#include "TGame.h"

namespace Console {
namespace Objects {

//TGame::TGame(): 
//    TObject(),
//    children(QList<uint16_t>()),
//    current_level(0)
//{
//}


TGame::TGame(uint16_t id, uint16_t w, uint16_t h, QColor bgc, uint16_t current_level): 
    TObject(TObject::TYPE_GAME, id, w, h, bgc),
    children(QList<uint16_t>()),
    current_level(current_level)
{
}


TGame::~TGame()
{
}


void TGame::add_score_id(uint16_t score_id)
{
    score_id = score_id;
}


uint16_t TGame::get_score_id()
{
    return score_id;
}


void TGame::add_child(uint16_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TGame::get_children()
{
    return children;
}


void TGame::set_current_level(uint16_t bs)
{
    current_level = bs;
}    


uint16_t TGame::get_current_level()
{
    return current_level;
}


} // namespace Objects
} // namespace Console
