#include "gameObjects/Bound.hpp"

Bound::Bound(std::shared_ptr<Graphic::ObjectDrawingBase> graphic, std::shared_ptr<Physic::BoundPhysic> physic) {
    _graphic = graphic;
    _physic = physic;
    _updateGraficPosition();
}

void Bound::Update(UpdateEventDto updateEventDto) {
    _updateGraficPosition();
}

shared_ptr<ObjectDrawingBase> Bound::GetDrawing() const {
    return _graphic;
}

void Bound::_updateGraficPosition() {
    _graphic->SetPosition(_physic->GetPosition());
}
