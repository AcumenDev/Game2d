#include <DrawingObject.hpp>

DrawingObject::DrawingObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint){
    _texture = texture;
    _iPoint = iPoint;
    _log=log;
    _isLive = true;
}

void DrawingObject::Draw() {
    _texture->Draw(_iPoint);
}


bool DrawingObject::IsLive() {
    return _isLive;
}
