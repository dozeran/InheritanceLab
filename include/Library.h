#pragma once

#include "InventoryItem.h"

#include <memory>
#include <vector>

class Library {
public:
    void add(std::unique_ptr<InventoryItem> item);

    std::size_t size() const noexcept;

    const InventoryItem& at(std::size_t index) const;

    void printAll() const;

    void printItemsFromYear(int year) const;

private:
    std::vector<std::unique_ptr<InventoryItem>> items_;
};