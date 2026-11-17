#pragma once

#include <string>
#include "Money.h"

class InventoryItem {
public:
    int getInventoryNumber() const noexcept;
    const std::string& getName() const noexcept;
    int getPurchaseYear() const noexcept;
    const Money& getReplacementValue() const noexcept;

    void describe() const;
    void describe(int width) const;

    virtual ~InventoryItem();

protected:
    InventoryItem(int inventoryNumber,
                  const std::string& name,
                  int purchaseYear,
                  const Money& replacementValue);

private:
    int inventoryNumber_;
    std::string name_;
    int purchaseYear_;
    Money replacementValue_;
};