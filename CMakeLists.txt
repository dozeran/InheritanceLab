
cmake_minimum_required(VERSION 3.16)

project(InheritanceLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(inventory_lib
    src/Money.cpp
    src/InventoryItem.cpp
    src/GroupEquipment.cpp
    src/PersonalEquipment.cpp
    src/Library.cpp
    src/Loan.cpp
)

target_include_directories(inventory_lib PUBLIC include)

add_executable(InheritanceLab
    src/main.cpp
)

target_link_libraries(InheritanceLab PRIVATE inventory_lib)

add_executable(DestructorTest
    experiments/destructor_test.cpp
)

target_link_libraries(DestructorTest PRIVATE inventory_lib)

add_executable(InheritanceTests
    tests/test_inheritance.cpp
)

target_link_libraries(InheritanceTests
    PRIVATE inventory_lib GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(InheritanceTests)
