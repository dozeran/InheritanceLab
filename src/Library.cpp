#include "Library.h"

#include <iostream>
#include <stdexcept>

void Library::add(std::unique_ptr<InventoryItem> item) {
    if (!item) {
        throw std::invalid_argument("Cannot add a null inventory item");
    }

    items_.push_back(std::move(item));
}

std::size_t Library::size() const noexcept {
    return items_.size();
}

const InventoryItem& Library::at(std::size_t index) const {
    return *items_.at(index);
}

void Library::printAll() const {
    for (const auto& item : items_) {
        std::cout << "Inventory number: "
                  << item->getInventoryNumber()
                  << ", Name: " << item->getName()
                  << ", Purchase year: " << item->getPurchaseYear()
                  << ", Replacement value: " << item->getReplacementValue()
                  << '\n';
    }
}

void Library::printItemsFromYear(int year) const {
    for (const auto& item : items_) {
        if (item->getPurchaseYear() >= year) {
            std::cout << item->getInventoryNumber()
                      << " - " << item->getName()
                      << " (" << item->getPurchaseYear() << ")\n";
        }
    }
}