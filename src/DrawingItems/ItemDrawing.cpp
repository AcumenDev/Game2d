#include "DrawingItems/ItemDrawing.hpp"

ItemDrawing::ItemDrawing(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint)
    :DrawingObject( log, texture, iPoint) {
}

ItemDrawing::~ItemDrawing() {
    //dtor
}

void ItemDrawing::Draw() {
    _texture->Draw(_iPoint);
}

void ItemDrawing::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
    auto event = eventInputSystem->event;
    switch(event.type) {
    case SDL_MOUSEBUTTONDOWN: {
        auto point=IPoint(event.motion.x, event.motion.y);
        auto rect= IRectangle(_iPoint.x, _iPoint.y, _texture->getWidth(), _texture->getHeight());
        if (_checkItemSelected( rect,point)) {
            _log->Info(std::to_string(event.motion.x));
        }
        break;
    }
    }
}


