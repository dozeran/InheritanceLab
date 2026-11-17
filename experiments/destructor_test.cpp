#include "GroupEquipment.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "Creating object...\n";

    std::unique_ptr<InventoryItem> item =
        std::make_unique<GroupEquipment>(
            101, "Basketballs", 2024, Money(1200, 0), 10
        );

    std::cout << "Deleting object...\n";

    item.reset();

    std::cout << "Program finished.\n";

    return 0;
}