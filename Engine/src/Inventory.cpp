#include "Inventory.hpp"

Inventory::Inventory(std::shared_ptr<Logger> log, std::shared_ptr<Texture> textureCell, IPoint iPoint, int size)
    :DrawingObject(log, textureCell, iPoint) {
    _size = size;

    _textureCell = textureCell;
}

Inventory::~Inventory() {

}

void Inventory::Draw() {
    for(int i = 0; i<_size; i++) {
        _textureCell->Draw(IPoint(_iPoint.x,_iPoint.y+_textureCell->getHeight()*i));
    }


    for(auto const& item : _inventoryItems) {
        item->Draw();
    }
}

void Inventory::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
    for(auto const& item : _inventoryItems) {
        item->Update(delta,eventInputSystem );
    }
}
void Inventory::Add(std::shared_ptr<InventoryItem> item) {
    _inventoryItems.push_back(item);
}
