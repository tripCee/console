#include "TGame.h"

namespace Console {
namespace Objects {

//TGame::TGame(): 
//    TObject(),
//    children(QList<uint16_t>()),
//    current_level(0)
//{
//}


TGame::TGame(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, uint16_t current_level): 
    TObject(TObject::TYPE_GAME, id, w, h, bw, bgc),
    score_id(0),
    children(QList<object_id_t>()),
    current_level(current_level)
{
}


TGame::~TGame()
{
}


void TGame::set_score_id(object_id_t id)
{
    score_id = id;
}


object_id_t TGame::get_score_id()
{
    return score_id;
}


void TGame::set_control_id(object_id_t id)
{
    control_id = id;
}


object_id_t TGame::get_control_id()
{
    return control_id;
}


void TGame::set_storage_id(object_id_t id)
{
    storage_id = id;
}


object_id_t TGame::get_storage_id()
{
    return storage_id;
}


void TGame::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<object_id_t>& TGame::get_children()
{
    return children;
}


object_id_t TGame::get_current_board_id()
{
    return children[current_level-1];
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
