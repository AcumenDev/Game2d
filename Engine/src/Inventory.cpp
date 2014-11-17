#include "Inventory.hpp"

Inventory::Inventory(std::shared_ptr<Logger> log, std::shared_ptr<Texture> textureCell, IPoint iPoint, int maxSize, int borderSize)
    :DrawingObject(log, textureCell, iPoint) {
    _maxSize = maxSize;
    _textureCell = textureCell;
    _borderSize  = borderSize;
}

Inventory::~Inventory() {

}

void Inventory::Draw() {
    for(int i = 0; i<_maxSize; i++) {
        _textureCell->Draw(IPoint(_iPoint.x,_iPoint.y+_textureCell->getHeight()*i));
    }

    for( unsigned int i = 0; i<_inventoryItems.size(); i++) {
        //_textureCell->Draw(IPoint(_iPoint.x,_iPoint.y+_textureCell->getHeight()*i));
        _inventoryItems.at(i)->Draw(IPoint(_iPoint.x,_iPoint.y+_borderSize+_textureCell->getHeight()*i));
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
