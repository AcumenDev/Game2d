#include "ObjectsDrawing/BackgroundObject.hpp"

BackgroundObject::BackgroundObject(std::shared_ptr<Texture> texture, FPoint point)
        : DrawingObject(texture, point) {
}

BackgroundObject::~BackgroundObject() {
}

void BackgroundObject::Draw() {
    _texture->Draw(_point);
}

void BackgroundObject::Update(UpdateEventDto updateEventDto) {

}
