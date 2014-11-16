#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "DrawingObject.hpp"
#include "Utils/IPoint.hpp"

class InventoryItem  {
public:
    InventoryItem(std::shared_ptr<Texture> texture);
    virtual ~InventoryItem();
    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem);
    void Draw(IPoint iPoint);
private:
    std::shared_ptr<Texture> _texture;
};

#endif // INVENTORYITEM_H
