#include "TScore.h"

namespace Console {
namespace Objects {

TScore::TScore(): 
    TObject(),
    children(QList<object_id_t>())
{
}


TScore::TScore(object_id_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_SCORE, id, w, h, bgc),
    children(QList<object_id_t>())
{
}


TScore::~TScore()
{
}


void TScore::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<object_id_t>& TScore::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
