#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "DrawingObject.hpp"
#include "Utils/IPoint.hpp"

class InventoryItem  {
public:
    InventoryItem(const int &id, std::shared_ptr<Texture> texture);
    virtual ~InventoryItem();
    void Update(UpdateEventDto updateEventDto);
    void Draw(IPoint iPoint);
private:
    std::shared_ptr<Texture> _texture;
    int _id;
public:
    int GetId();
};

#endif // INVENTORYITEM_H
