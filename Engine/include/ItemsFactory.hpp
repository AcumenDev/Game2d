#ifndef ITEMSFACTORY_H
#define ITEMSFACTORY_H
#include <map>
#include <ObjectsDrawing/Inventory/InventoryItem.hpp>
#include "ResourceManager.hpp"
#include "Logger.hpp"

class ItemsFactory
{
public:
    ItemsFactory(
            std::shared_ptr<Logger> log,
            std::map<int, std::string> const &items,
            std::shared_ptr<ResourceManager> const &resourceManager);
    ItemsFactory(std::shared_ptr<ResourceManager> resourceManager, std::map<int, std::string> items);
    std::shared_ptr<InventoryItem> GetItemForId(int id);
    virtual ~ItemsFactory();
private:
    std::map<int, std::string> _items;
    std::shared_ptr<ResourceManager> _resourceManager;
    std::shared_ptr<Logger> _log;
};

#endif