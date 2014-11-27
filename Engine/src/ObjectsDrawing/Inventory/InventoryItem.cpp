#include "ObjectsDrawing/Inventory/InventoryItem.hpp"

InventoryItem::InventoryItem(std::shared_ptr<Texture> texture) {
    _texture=  texture;
}

InventoryItem::~InventoryItem() {
}

void InventoryItem::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
}

void InventoryItem::Draw(IPoint iPoint) {
    _texture->Draw(iPoint);
}

