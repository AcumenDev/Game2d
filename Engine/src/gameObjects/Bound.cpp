#include "gameObjects/Bound.hpp"

Bound::Bound(std::shared_ptr<Graphic::ObjectDrawingBase> graphic, std::shared_ptr<Physic::BoundPhysic> physic) {
    _graphic = graphic;
    _physic = physic;
}

void Bound::Update(UpdateEventDto updateEventDto) {
    _graphic->SetPosition(_physic->GetPosition());
}

shared_ptr<ObjectDrawingBase> Bound::GetDrawing() const {
    return _graphic;
}
