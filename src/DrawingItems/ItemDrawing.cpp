#include "DrawingItems/ItemDrawing.hpp"

ItemDrawing::ItemDrawing(std::shared_ptr<Texture> texture, FPoint point, std::string name)
        : DrawingObject(texture, point) {
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

    auto event = updateEventDto.eventInputSystem->GetEvent();
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN : {
           // auto cameraPosition = Render::Get()->GetCamera()->GetPosition();

            auto point =Render::Get()->ToWorldCoordinate(FPoint(event.motion.x,event.motion.y));//  FPoint(event.motion.x + cameraPosition.x, event.motion.y + cameraPosition.y);
            auto rect = FRectangle(_point, FPoint(_texture->getWidth(), _texture->getHeight()));
            if (_checkItemSelected(rect, point)) {
                Logger::Get()->Info("ItemDrawing", "Take an item :" + _name);
                updateEventDto.notificationServices->Notify("inventoryAdd", 0);
                _notyfy = true;
                _isLive = false;
            }
            break;
        }
    }
}


