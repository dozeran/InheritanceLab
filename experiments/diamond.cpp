#include "InventoryItem.h"

#include <iostream>
#include <memory>

// Перша проміжна гілка
class TeamEquipment : public virtual InventoryItem {
public:
    TeamEquipment(int id, const std::string& name,
                  int year, const Money& value)
        : InventoryItem(id, name, year, value) {
        std::cout << "TeamEquipment constructor\n";
    }
};

// Друга проміжна гілка
class SafetyEquipment : public virtual InventoryItem {
public:
    SafetyEquipment(int id, const std::string& name,
                    int year, const Money& value)
        : InventoryItem(id, name, year, value) {
        std::cout << "SafetyEquipment constructor\n";
    }
};

// Найпохідніший клас
class MultiPurposeEquipment final
    : public TeamEquipment,
      public SafetyEquipment {
public:
    MultiPurposeEquipment(int id,
                          const std::string& name,
                          int year,
                          const Money& value)
        : InventoryItem(id, name, year, value),
          TeamEquipment(id, name, year, value),
          SafetyEquipment(id, name, year, value) {
        std::cout << "MultiPurposeEquipment constructor\n";
    }
};

int main() {
    std::cout << "=== VIRTUAL INHERITANCE ===\n";

    MultiPurposeEquipment equipment(
        301,
        "Professional protective set",
        2025,
        Money(5000, 0)
    );

    std::cout << "\nInventory number: "
              << equipment.getInventoryNumber() << '\n';

    std::cout << "Name: "
              << equipment.getName() << '\n';

    InventoryItem* item = &equipment;

    std::cout << "Base pointer conversion: "
              << item->getName() << '\n';

    std::cout << "\nObject sizes:\n";
    std::cout << "InventoryItem: "
              << sizeof(InventoryItem) << " bytes\n";

    std::cout << "MultiPurposeEquipment: "
              << sizeof(MultiPurposeEquipment) << " bytes\n";

    return 0;
}