#include <DrawingObject.hpp>

DrawingObject::DrawingObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, FPoint point){
    _texture = texture;
    _point = point;
    _log=log;
    _isLive = true;
}

void DrawingObject::Draw() {
    _texture->Draw(_point);
}


bool DrawingObject::IsLive() {
    return _isLive;
}
