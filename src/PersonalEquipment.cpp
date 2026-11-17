#include "PersonalEquipment.h"

#include <iostream>

PersonalEquipment::PersonalEquipment(int inventoryNumber,
                                     const std::string& name,
                                     int purchaseYear,
                                     const Money& replacementValue,
                                     const std::string& size)
    : InventoryItem(inventoryNumber, name, purchaseYear, replacementValue),
      size_(size) {
}

const std::string& PersonalEquipment::getSize() const noexcept {
    return size_;
}

PersonalEquipment::~PersonalEquipment() {
}