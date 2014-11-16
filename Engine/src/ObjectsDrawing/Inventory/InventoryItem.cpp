#include "InventoryItem.hpp"

InventoryItem::InventoryItem(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint)
    :DrawingObject(log, texture, iPoint) {
}

InventoryItem::~InventoryItem() {

}

void InventoryItem::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {

}

