#include "SelectableDrawingObject.hpp"

SelectableDrawingObject::SelectableDrawingObject() {
    //ctor
}

SelectableDrawingObject::~SelectableDrawingObject() {
    //dtor
}

bool SelectableDrawingObject::_checkItemSelected(IRectangle rect, IPoint point) {
    auto checkX=point.x>=rect.x;
    auto checkY=point.y >=rect.y;
    auto checkWidth=point.x<=(rect.x+rect.w);
    auto checkHeight=point.y<=(rect.y+rect.h);

    return checkX&&checkY&&checkWidth&&checkHeight;
}
