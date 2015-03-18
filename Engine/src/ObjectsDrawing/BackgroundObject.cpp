#include "ObjectsDrawing/BackgroundObject.hpp"
namespace Graphic {
    BackgroundObject::BackgroundObject(std::shared_ptr<Texture> texture, FPoint point)
    {
        _texture = texture;
        _point = point;
    }

    BackgroundObject::~BackgroundObject() {
    }

    void BackgroundObject::Draw() {
        _texture->Draw(_point);
    }

    void BackgroundObject::SetPosition(FPoint const &fPoint) {

    }
}