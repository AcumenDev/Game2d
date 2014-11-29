#include <ObjectsDrawing/Inventory/Inventory.hpp>

Inventory::Inventory(std::shared_ptr<Logger> log, std::shared_ptr<Texture> textureCell,std::shared_ptr<ItemsFactory> itemsFactory, IPoint iPoint, int maxSize, int borderSize)
    :DrawingObject(log, textureCell, iPoint) {
    _maxSize = maxSize;
    _textureCell = textureCell;
    _borderSize  = borderSize;
    _itemsFactory = itemsFactory;
}

Inventory::~Inventory() {

}

void Inventory::Draw() {
    for(int i = 0; i<_maxSize; i++) {
        _textureCell->Draw(IPoint(_iPoint.x,_iPoint.y+_textureCell->getHeight()*i));
    }

    for( unsigned int i = 0; i<_inventoryItems.size(); i++) {
        //_textureCell->Draw(IPoint(_iPoint.x,_iPoint.y+_textureCell->getHeight()*i));
        _inventoryItems.at(i)->Draw(IPoint(_iPoint.x,_iPoint.y+_borderSize+_textureCell->getHeight()*i));
    }


}

void Inventory::Update(UpdateEventDto updateEventDto) {
    for(auto const& item : _inventoryItems) {
        item->Update(updateEventDto );
    }
}
void Inventory::Add(std::shared_ptr<InventoryItem> item) {
    _log->Info("Inventory","Added to Inventory :"+ std::to_string(item->GetId()));
    _inventoryItems.push_back(item);
}


void Inventory::AddItem(const int &itemId) {
    Add( _itemsFactory->GetItemForId(itemId));
}
