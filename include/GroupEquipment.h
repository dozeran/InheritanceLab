#pragma once

#include "InventoryItem.h"

class GroupEquipment : public InventoryItem {
public:
    GroupEquipment(int inventoryNumber,
                   const std::string& name,
                   int purchaseYear,
                   const Money& replacementValue,
                   int quantity);

    int getQuantity() const noexcept;
    Money calculateTotalValue() const;

    using InventoryItem::describe;

    void describe() const;

    ~GroupEquipment() override;

private:
    int quantity_;
};