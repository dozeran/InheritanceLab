#pragma once

#include "InventoryItem.h"

#include <string>

class Loan {
public:
    Loan(int readerId,
         const InventoryItem& item,
         const std::string& issueDate,
         const std::string& returnDate);

    int getReaderId() const noexcept;
    const InventoryItem& getItem() const noexcept;
    const std::string& getIssueDate() const noexcept;
    const std::string& getReturnDate() const noexcept;

private:
    int readerId_;
    const InventoryItem* item_;
    std::string issueDate_;
    std::string returnDate_;
};