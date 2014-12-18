#include "DrawingItems/ItemDrawing.hpp"

ItemDrawing::ItemDrawing(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, FPoint point, std::string name)
        : DrawingObject(log, texture, point) {
    _notyfy = false;
    _name = name;
}

ItemDrawing::~ItemDrawing() {
}

void ItemDrawing::Draw() {
    _texture->Draw(_point);
}

void ItemDrawing::Update(UpdateEventDto updateEventDto) {
    if (_notyfy) {
        return;
    }

    auto event = updateEventDto.eventInputSystem->event;
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN : {
            auto point = FPoint(event.motion.x, event.motion.y);
            auto rect = FRectangle(_point, FPoint(_texture->getWidth(), _texture->getHeight()));
            if (_checkItemSelected(rect, point)) {
                _log->Info("ItemDrawing", "Take an item :" + _name);
                updateEventDto.notificationServices->Notify("inventoryAdd", 0);
                _notyfy = true;
                _isLive = false;
            }
            break;
        }
    }
}


