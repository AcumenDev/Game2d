#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "DrawingObject.hpp"

class InventoryItem : public DrawingObject {
public:
    InventoryItem(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~InventoryItem();
    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) override;
};

#endif // INVENTORYITEM_H
