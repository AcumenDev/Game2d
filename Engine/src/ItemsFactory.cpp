#include "ItemsFactory.hpp"

ItemsFactory::ItemsFactory(std::map<int, std::string> const &_items, std::shared_ptr<ResourceManager> const &_resourceManager)
        : _items(_items), _resourceManager(_resourceManager) {
}

std::shared_ptr<InventoryItem> ItemsFactory::GetItemForId(int id) {

        auto itemDto = _items.at(id);
        return std::make_shared<InventoryItem>(id, _resourceManager->GetTextureFromFile(itemDto));
}

ItemsFactory::~ItemsFactory() {
}

