#include "TScore.h"

namespace Console {
namespace Objects {

TScore::TScore(): 
    TObject(),
    children(QMap<object_id_t, QPoint>())
{
}


TScore::TScore(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc): 
    TObject(TObject::TYPE_SCORE, id, w, h, bw, bgc),
    children(QMap<object_id_t, QPoint>())
{
}


TScore::~TScore()
{
}


void TScore::add_child(object_id_t cid, QPoint pos)
{
    children.insert(cid, pos);
}


const QMap<object_id_t, QPoint>& TScore::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
