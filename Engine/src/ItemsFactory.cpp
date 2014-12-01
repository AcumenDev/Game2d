#include "ItemsFactory.hpp"

ItemsFactory::ItemsFactory(
        std::shared_ptr<Logger> log,
        std::map<int, std::string> const &_items,
        std::shared_ptr<ResourceManager> const &_resourceManager)
        : _items(_items), _resourceManager(_resourceManager), _log(log) {
}

std::shared_ptr<InventoryItem> ItemsFactory::GetItemForId(int id) {
        try{
                auto itemDto = _items.at(id);
                return std::make_shared<InventoryItem>(id, _resourceManager->GetTextureFromFile(itemDto));
        }catch (std::exception ex){
                _log->Error("ItemsFactory", "In items factory not found item "+std::to_string(id) +" ex -"+ex.what());
        }

        return nullptr;
}

ItemsFactory::~ItemsFactory() {
}

