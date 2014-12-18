#include "ObjectsDrawing/Inventory/InventoryItem.hpp"

InventoryItem::InventoryItem(const int &id, std::shared_ptr<Texture> texture) {
    _texture=  texture;
    _id = id;
}

InventoryItem::~InventoryItem() {
}

void InventoryItem::Update(UpdateEventDto updateEventDto) {
}

void InventoryItem::Draw(FPoint point) {
    _texture->Draw(point);
}

int InventoryItem::GetId()
{
    return _id;
}