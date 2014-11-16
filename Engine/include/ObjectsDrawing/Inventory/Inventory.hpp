#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include <vector>
#include "DrawingObject.hpp"
#include "InventoryItem.hpp"
class Inventory : public DrawingObject {
public:
    /** Default constructor */
    Inventory(std::shared_ptr<Logger> log, std::shared_ptr<Texture> textureCell, IPoint iPoint, int size);
    /** Default destructor */
    virtual ~Inventory();
    void Draw() override;
    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) override;
    void Add(std::shared_ptr<InventoryItem> item);
protected:
private:
    std::vector<std::shared_ptr<InventoryItem>> _inventoryItems;
    int _size;
    std::shared_ptr<Texture> _textureCell;
};
#endif // INVENTORY_H
