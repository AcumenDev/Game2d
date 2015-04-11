#include "gameObjects/weapons/Akm.hpp"

void Akm::Update(UpdateEventDto updateEventDto) {

}

shared_ptr <ObjectDrawingBase> Akm::GetDrawing() const {
    return _graphic;
}


Akm::Akm(shared_ptr<Graphic::ObjectDrawingBase> graphic) {
_graphic = graphic;
}
