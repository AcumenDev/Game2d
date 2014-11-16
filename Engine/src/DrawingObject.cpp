#include "Engine.hpp"

DrawingObject::DrawingObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint) {
    _texture = texture;
    _iPoint = iPoint;
    _log=log;
}

void DrawingObject::Draw()
{
   _texture->Draw(_iPoint);
}
