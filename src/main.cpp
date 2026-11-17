#include "Library.h"
#include "GroupEquipment.h"
#include "PersonalEquipment.h"
#include "Loan.h"

#include <iostream>
#include <memory>

void byValue(InventoryItem item) {
    std::cout << "Passed by value: "
              << item.getName() << '\n';

    std::cout << "Object size: "
              << sizeof(item) << " bytes\n";
}

void byReference(const InventoryItem& item) {
    std::cout << "Passed by reference: "
              << item.getName() << '\n';

    if (const auto* group =
            dynamic_cast<const GroupEquipment*>(&item)) {
        std::cout << "Quantity: "
                  << group->getQuantity() << '\n';
    }
}

int main() {
    Library library;

    // Груповий спортивний інвентар
    library.add(std::make_unique<GroupEquipment>(
        101, "Basketballs", 2024, Money(1200, 0), 10
    ));

    library.add(std::make_unique<GroupEquipment>(
        102, "Football balls", 2023, Money(900, 0), 15
    ));

    // Особисте спортивне спорядження
    library.add(std::make_unique<PersonalEquipment>(
        201, "Boxing gloves", 2025, Money(1800, 0), "L"
    ));

    library.add(std::make_unique<PersonalEquipment>(
        202, "Sports helmet", 2024, Money(1500, 0), "M"
    ));

    std::cout << "=== SPORT EQUIPMENT LIBRARY ===\n";
    library.printAll();

    std::cout << "\n=== ITEMS FROM 2024 ===\n";
    library.printItemsFromYear(2024);

    std::cout << "\nTotal number of items: "
              << library.size() << '\n';

    std::cout << "\n=== GROUP EQUIPMENT DETAILS ===\n";

    const auto* groupItem =
        dynamic_cast<const GroupEquipment*>(&library.at(0));

    if (groupItem) {
        std::cout << "Quantity: " << groupItem->getQuantity() << '\n';
        std::cout << "Total value: "
                  << groupItem->calculateTotalValue() << '\n';
    }

    std::cout << "\n=== PERSONAL EQUIPMENT DETAILS ===\n";

    const auto* personalItem =
        dynamic_cast<const PersonalEquipment*>(&library.at(2));

    if (personalItem) {
        std::cout << "Size: " << personalItem->getSize() << '\n';
    }

    std::cout << "\n=== METHOD HIDING DEMONSTRATION ===\n";

    const auto& group = static_cast<const GroupEquipment&>(library.at(0));

    group.describe();
    group.describe(40);

    std::cout << "\n=== OBJECT SLICING DEMONSTRATION ===\n";

    const auto& groupForSlicing =
    static_cast<const GroupEquipment&>(library.at(0));

    byValue(groupForSlicing);
    byReference(groupForSlicing);

    std::cout << "\n=== LOAN DEMONSTRATION ===\n";

    Loan loan(
        5001,
        library.at(0),
        "2026-11-17",
        "2026-11-24"
    );

    std::cout << "Reader ID: " << loan.getReaderId() << '\n';
    std::cout << "Equipment: " << loan.getItem().getName() << '\n';
    std::cout << "Issue date: " << loan.getIssueDate() << '\n';
    std::cout << "Return date: " << loan.getReturnDate() << '\n';

    return 0;
}