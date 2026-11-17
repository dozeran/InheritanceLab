
#include <gtest/gtest.h>

#include "InventoryItem.h"
#include "GroupEquipment.h"
#include "PersonalEquipment.h"
#include "Library.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

// Допоміжна функція для перевірки передачі похідного об'єкта
// у функцію, яка приймає посилання на базовий клас.
const InventoryItem& acceptBaseReference(const InventoryItem& item) {
    return item;
}

// Тестовий клас для перевірки знищення об'єктів.
class TrackingEquipment : public InventoryItem {
public:
    static int destroyedCount;

    TrackingEquipment()
        : InventoryItem(999, "Test equipment", 2025, Money(100, 0)) {}

    ~TrackingEquipment() override {
        ++destroyedCount;
    }
};

int TrackingEquipment::destroyedCount = 0;

// 1. Похідний об'єкт можна передати у функцію
//    через посилання на базовий клас.
TEST(InheritanceTest, DerivedObjectAcceptedByBaseReference) {
    GroupEquipment basketballs(
        101, "Basketballs", 2024, Money(1200, 0), 10
    );

    const InventoryItem& item = acceptBaseReference(basketballs);

    EXPECT_EQ(item.getName(), "Basketballs");
    EXPECT_EQ(item.getInventoryNumber(), 101);
}

// 2. Гетери базового класу повертають значення,
//    передані через конструктор.
TEST(InheritanceTest, BaseGettersReturnConstructorValues) {
    GroupEquipment equipment(
        102, "Football balls", 2023, Money(900, 0), 15
    );

    EXPECT_EQ(equipment.getInventoryNumber(), 102);
    EXPECT_EQ(equipment.getName(), "Football balls");
    EXPECT_EQ(equipment.getPurchaseYear(), 2023);
    EXPECT_EQ(equipment.getReplacementValue(), Money(900, 0));
}

// 3. Бібліотека зберігає різні похідні типи
//    у порядку додавання.
TEST(InheritanceTest, LibraryStoresMixedTypesInInsertionOrder) {
    Library library;

    library.add(std::make_unique<GroupEquipment>(
        101, "Basketballs", 2024, Money(1200, 0), 10
    ));

    library.add(std::make_unique<PersonalEquipment>(
        201, "Boxing gloves", 2025, Money(1800, 0), "L"
    ));

    ASSERT_EQ(library.size(), 2);

    EXPECT_EQ(library.at(0).getName(), "Basketballs");
    EXPECT_EQ(library.at(1).getName(), "Boxing gloves");

    EXPECT_NE(
        dynamic_cast<const GroupEquipment*>(&library.at(0)),
        nullptr
    );

    EXPECT_NE(
        dynamic_cast<const PersonalEquipment*>(&library.at(1)),
        nullptr
    );
}

// 4. Знищення бібліотеки звільняє всі об'єкти.
TEST(InheritanceTest, LibraryDestroysAllItems) {
    TrackingEquipment::destroyedCount = 0;

    {
        Library library;

        library.add(std::make_unique<TrackingEquipment>());
        library.add(std::make_unique<TrackingEquipment>());

        EXPECT_EQ(TrackingEquipment::destroyedCount, 0);
    }

    EXPECT_EQ(TrackingEquipment::destroyedCount, 2);
}

// 5. using відновлює доступ до обох перевантажень describe().
TEST(InheritanceTest, UsingRestoresDescribeOverloads) {
    GroupEquipment equipment(
        101, "Basketballs", 2024, Money(1200, 0), 10
    );

    std::ostringstream output;
    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    equipment.describe();
    equipment.describe(40);

    std::cout.rdbuf(oldBuffer);

    EXPECT_NE(
        output.str().find("Group equipment: Basketballs"),
        std::string::npos
    );

    EXPECT_NE(
        output.str().find("Basketballs"),
        std::string::npos
    );
}

// 6. Фільтр за роком знаходить обидва похідні типи.
TEST(InheritanceTest, YearFilterWorksForBothDerivedTypes) {
    Library library;

    library.add(std::make_unique<GroupEquipment>(
        101, "Basketballs", 2024, Money(1200, 0), 10
    ));

    library.add(std::make_unique<PersonalEquipment>(
        201, "Boxing gloves", 2024, Money(1800, 0), "L"
    ));

    library.add(std::make_unique<GroupEquipment>(
        102, "Football balls", 2023, Money(900, 0), 15
    ));

    std::ostringstream output;
    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    library.printItemsFromYear(2024);

    std::cout.rdbuf(oldBuffer);

    EXPECT_NE(
        output.str().find("Basketballs"),
        std::string::npos
    );

    EXPECT_NE(
        output.str().find("Boxing gloves"),
        std::string::npos
    );

    EXPECT_EQ(
        output.str().find("Football balls"),
        std::string::npos
    );
}
