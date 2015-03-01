#include "ItemsFactory.hpp"

ItemsFactory::ItemsFactory(
        std::map<int, std::string> const &_items,
        std::shared_ptr<TexturesResourceManager> const &_resourceManager)
        : _items(_items), _resourceManager(_resourceManager) {
}

std::shared_ptr<InventoryItem> ItemsFactory::GetItemForId(int id) {
    try {
        auto itemDto = _items.at(id);
        return std::make_shared<InventoryItem>(id, _resourceManager->getResourse(itemDto));
    } catch (std::exception ex) {
        Logger::Get()->Error("ItemsFactory", "In items factory not found item " + std::to_string(id) + " ex -" + ex.what());
    }

    return nullptr;
}

ItemsFactory::~ItemsFactory() {
}

