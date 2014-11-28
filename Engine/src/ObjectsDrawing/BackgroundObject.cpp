#include "ObjectsDrawing/BackgroundObject.hpp"

BackgroundObject::BackgroundObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint)
    :DrawingObject(log,texture,iPoint) {
}

BackgroundObject::~BackgroundObject() {
}

void BackgroundObject::Draw() {
    _texture->Draw(_iPoint);
}

void BackgroundObject::Update(UpdateEventDto updateEventDto) {
}


