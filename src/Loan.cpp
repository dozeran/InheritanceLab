#include "Loan.h"

Loan::Loan(int readerId,
           const InventoryItem& item,
           const std::string& issueDate,
           const std::string& returnDate)
    : readerId_(readerId),
      item_(&item),
      issueDate_(issueDate),
      returnDate_(returnDate) {
}

int Loan::getReaderId() const noexcept {
    return readerId_;
}

const InventoryItem& Loan::getItem() const noexcept {
    return *item_;
}

const std::string& Loan::getIssueDate() const noexcept {
    return issueDate_;
}

const std::string& Loan::getReturnDate() const noexcept {
    return returnDate_;
}