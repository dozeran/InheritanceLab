#pragma once

#include "InventoryItem.h"
#include <string>

class PersonalEquipment : public InventoryItem {
public:
    PersonalEquipment(int inventoryNumber,
                      const std::string& name,
                      int purchaseYear,
                      const Money& replacementValue,
                      const std::string& size);

    const std::string& getSize() const noexcept;

    ~PersonalEquipment() override;

private:
    std::string size_;
};