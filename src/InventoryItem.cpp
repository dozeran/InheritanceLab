#include "InventoryItem.h"

#include <iostream>
#include <iomanip>

InventoryItem::InventoryItem(int inventoryNumber,
                             const std::string& name,
                             int purchaseYear,
                             const Money& replacementValue)
    : inventoryNumber_(inventoryNumber),
      name_(name),
      purchaseYear_(purchaseYear),
      replacementValue_(replacementValue) {
}

int InventoryItem::getInventoryNumber() const noexcept {
    return inventoryNumber_;
}

const std::string& InventoryItem::getName() const noexcept {
    return name_;
}

int InventoryItem::getPurchaseYear() const noexcept {
    return purchaseYear_;
}

const Money& InventoryItem::getReplacementValue() const noexcept {
    return replacementValue_;
}

void InventoryItem::describe() const {
    std::cout << "Inventory item: " << name_ << '\n';
}

void InventoryItem::describe(int width) const {
    std::cout << std::setw(width) << name_ << '\n';
}

InventoryItem::~InventoryItem() {
}