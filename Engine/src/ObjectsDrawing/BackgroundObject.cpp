#include "BackgroundObject.hpp"

BackgroundObject::BackgroundObject(std::shared_ptr<Texture> texture, IPoint iPoint) {
    _texture = texture;
    _iPoint = iPoint;
}

BackgroundObject::~BackgroundObject() {
}

void BackgroundObject::Draw() {
    _texture->Draw(_iPoint);
}

void BackgroundObject::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {

}
