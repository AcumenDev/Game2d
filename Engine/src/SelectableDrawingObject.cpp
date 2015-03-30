#include <render/Render.hpp>
#include "SelectableDrawingObject.hpp"

SelectableDrawingObject::SelectableDrawingObject() {
}

SelectableDrawingObject::~SelectableDrawingObject() {
}

bool SelectableDrawingObject::_checkItemSelected(FRectangle rect, FPoint point) {
   auto pointLocal =  Render::Get()->ToLocalCoordinate(point);
    auto checkX = pointLocal.x >= rect.LeftTop.x;
    auto checkY = pointLocal.y >= rect.LeftTop.y;
    auto checkWidth = pointLocal.x <= (rect.LeftTop.x + rect.RightBottom.x);
    auto checkHeight = pointLocal.y <= (rect.LeftTop.y + rect.RightBottom.y);
    return checkX && checkY && checkWidth && checkHeight;
}
