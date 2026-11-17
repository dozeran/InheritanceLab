#include "GroupEquipment.h"

#include <iostream>

GroupEquipment::GroupEquipment(int inventoryNumber,
                               const std::string& name,
                               int purchaseYear,
                               const Money& replacementValue,
                               int quantity)
    : InventoryItem(inventoryNumber, name, purchaseYear, replacementValue),
      quantity_(quantity) {
}

int GroupEquipment::getQuantity() const noexcept {
    return quantity_;
}

Money GroupEquipment::calculateTotalValue() const {
    return getReplacementValue() * quantity_;
}

void GroupEquipment::describe() const {
    std::cout << "Group equipment: " << getName()
              << ", quantity: " << quantity_ << '\n';
}

GroupEquipment::~GroupEquipment() {
}