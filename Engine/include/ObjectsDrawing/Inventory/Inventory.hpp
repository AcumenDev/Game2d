#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <vector>
#include "DrawingObject.hpp"
#include "InventoryItem.hpp"
#include <Utils/Point.hpp>
#include <DrawingObject.hpp>
#include <ItemsFactory.hpp>

using namespace Utils;

class Inventory
        : public DrawingObject // TODO Убрать наследование от DrawingObject  вместо него юзать ObjectDrawingBase
{
public:
    Inventory(
            std::shared_ptr<Texture> textureCell,
            std::shared_ptr<ItemsFactory> itemsFactory,
            FPoint point,
            int maxSize,
            int borderSize);

    virtual ~Inventory();

    void Draw() override;

    void Update(UpdateEventDto updateEventDto) override;

    void AddItemForId(const int &itemId);

protected:
    void Add(std::shared_ptr<InventoryItem> item);

private:
    std::vector<std::shared_ptr<InventoryItem>> _inventoryItems;
    int _maxSize;
    int _borderSize;
    std::shared_ptr<Texture> _textureCell;
    std::shared_ptr<ItemsFactory> _itemsFactory;
};

#endif // INVENTORY_H
