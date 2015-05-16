#include "gameObjects/weapons/Akm.hpp"

Akm::Akm(shared_ptr<Graphic::ObjectDrawingBase> graphic, shared_ptr<AkmScript> script) {
    _graphic = graphic;
    _script = script;
}

Akm::~Akm() {

}

void Akm::Update(UpdateEventDto updateEventDto) {

}

shared_ptr<ObjectDrawingBase> Akm::GetDrawing() const {
    return _graphic;
}

void Akm::Shot() {

}


void Akm::SetPosition(FPoint point) {
    auto position = _script->getPosition();
    point.y += position.y;
    point.x += position.x;

    _graphic->SetPosition(point);

}
