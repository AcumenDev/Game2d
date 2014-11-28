#include "ObjectsDrawing/Inventory/InventoryItem.hpp"

InventoryItem::InventoryItem(const int &id, std::shared_ptr<Texture> texture) {
    _texture=  texture;
    _id = id;
}

InventoryItem::~InventoryItem() {
}

void InventoryItem::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
}

void InventoryItem::Draw(IPoint iPoint) {
    _texture->Draw(iPoint);
}

int InventoryItem::GetId()
{
    return _id;
}