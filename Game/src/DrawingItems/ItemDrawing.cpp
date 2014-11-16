#include "ItemDrawing.hpp"

ItemDrawing::ItemDrawing(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint) {
    _texture = texture;
    _iPoint = iPoint;
    _log=log;
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
        auto checkX=event.motion.x>=_iPoint.x;
        auto checkY=event.motion.y >=_iPoint.y;
        auto checkWidth=event.motion.x<=(_iPoint.x+_texture->getWidth());
        auto checkHeight=event.motion.y<=(_iPoint.y+_texture->getHeight());
        if (checkX&&checkY&&checkWidth&&checkHeight){
        _log->Info(std::to_string(event.motion.x));
        }
        break;
    }
    }
}
