#ifndef ITEMSFACTORY_H
#define ITEMSFACTORY_H
#include <map>
#include <ObjectsDrawing/Inventory/InventoryItem.hpp>
#include <resourceManagers/TexturesResourceManager.hpp>
#include "utils/logger/Logger.hpp"

class ItemsFactory
{
public:
    ItemsFactory(
            std::map<int, std::string> const &items,
            std::shared_ptr<TexturesResourceManager> const &resourceManager);
    ItemsFactory(std::shared_ptr<TexturesResourceManager> resourceManager, std::map<int, std::string> items);
    std::shared_ptr<InventoryItem> GetItemForId(int id);
    virtual ~ItemsFactory();
private:
    std::map<int, std::string> _items;
    std::shared_ptr<TexturesResourceManager> _resourceManager;
};

#endif