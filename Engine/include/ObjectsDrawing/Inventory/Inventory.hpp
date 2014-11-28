#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include <vector>
#include "DrawingObject.hpp"
#include "InventoryItem.hpp"
#include <Utils/IPoint.hpp>
#include <DrawingObject.hpp>
#include <ItemsFactory.hpp>

class Inventory : public DrawingObject {
public:
    Inventory(
            std::shared_ptr<Logger> log,
            std::shared_ptr<Texture> textureCell,
            std::shared_ptr<ItemsFactory> itemsFactory,
            IPoint iPoint,
            int maxSize,
            int borderSize);
    virtual ~Inventory();
    void Draw() override;
    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem, std::shared_ptr<NotificationServices> notificationServices) override;
    void Add(std::shared_ptr<InventoryItem> item);
    void AddItem(const int &itemId);
protected:
private:
    std::vector<std::shared_ptr<InventoryItem>> _inventoryItems;
    int _maxSize;
    int _borderSize;
    std::shared_ptr<Texture> _textureCell;
    std::shared_ptr<ItemsFactory> _itemsFactory;
};
#endif // INVENTORY_H
