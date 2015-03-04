#include <ObjectsDrawing/Inventory/Inventory.hpp>

Inventory::Inventory(std::shared_ptr<Texture> textureCell,std::shared_ptr<ItemsFactory> itemsFactory, FPoint point, int maxSize, int borderSize)
    :DrawingObject(textureCell, point) {
    _maxSize = maxSize;
    _textureCell = textureCell;
    _borderSize  = borderSize;
    _itemsFactory = itemsFactory;
}

Inventory::~Inventory() {

}

void Inventory::Draw() {
    for(int i = 0; i<_maxSize; i++) {
        _textureCell->Draw(FPoint(_point.x,_point.y+_textureCell->getHeight()*i));
    }

    for( unsigned int i = 0; i<_inventoryItems.size(); i++) {
        _inventoryItems.at(i)->Draw(FPoint(_point.x,_point.y+_borderSize+_textureCell->getHeight()*i));
    }
}

void Inventory::Update(UpdateEventDto updateEventDto) {
    for(auto const& item : _inventoryItems) {
        item->Update(updateEventDto );
    }
}
void Inventory::Add(std::shared_ptr<InventoryItem> item) {
    Logger::Get()->Info("Inventory","Added to Inventory : "+ std::to_string(item->GetId()));
    _inventoryItems.push_back(item);
}

void Inventory::AddItemForId(const int &itemId) {
    auto item = _itemsFactory->GetItemForId(itemId);
    if(item!= nullptr) {
        Add(item);
    }
}
