// #include <gtest/gtest.h>
// #include "Inventory.hpp"
// #include "Item.hpp"
// #include "Player.hpp"  // Assuming the Player class is defined elsewhere
// #include <memory>  // For smart pointers

// // Concrete subclass of Item for testing purposes
// class TestItem : public Item {
// public:
//     TestItem(const std::string& name) : Item(name) {}

//     // Implement the pure virtual method for testing
//     void use(Player* player) override {
//         std::cout << "Using item: " << getName() << std::endl;
  // Debug log for use
//     }
// };

// // Test fixture for Inventory class
// class InventoryTest : public ::testing::Test {
// protected:
//     std::unique_ptr<Inventory> inventory;
  // Use unique_ptr for automatic memory management

//     void SetUp() override {
//         inventory = std::make_unique<Inventory>();
  // Initialize the inventory with smart pointer
//         std::cout << "Inventory initialized." << std::endl;  // Debug log
//     }

//     void TearDown() override {
//         std::cout << "Tearing down InventoryTest." << std::endl;
// Debug log
// No need to manually delete anything
// since unique_ptr will automatically clean up
//     }
// };

// // Test adding a valid item to the inventory
// TEST_F(InventoryTest, AddItem) {
//     std::unique_ptr<TestItem> item = std::make_unique<TestItem>("TestItem");
//     std::cout << "Adding item: " << item->getName() << std::endl;
  // Debug log
//     EXPECT_NO_THROW(inventory->addItem(item.get()));
  // Pass raw pointer to inventory
// }

// // Test removing a valid item from the inventory
// TEST_F(InventoryTest, RemoveItem) {
//     std::unique_ptr<TestItem> item = std::make_unique<TestItem>("TestItem");
//     inventory->addItem(item.get());  // Add item to the inventory
//     std::cout << "Removing item: " << item->getName() << std::endl;
  // Debug log
//     EXPECT_NO_THROW(inventory->removeItem(item.get()));
  // Remove item from inventory
// }

// // Test trying to remove an invalid item (nullptr)
// TEST_F(InventoryTest, RemoveInvalidItem) {
//     TestItem* item = nullptr;  // Invalid item (nullptr)
//     std::cout << "Removing invalid item: "
// << (item ? item->getName() : "null") << std::endl;
  // Debug log
//     EXPECT_NO_THROW(inventory->removeItem(item));
// Expect no exception when removing a nullptr
// }

// // Test getting an existing item by name
// TEST_F(InventoryTest, GetItemByName) {
//     std::unique_ptr<TestItem> item = std::make_unique<TestItem>("TestItem");
//     inventory->addItem(item.get());  // Add item to inventory
//     std::cout << "Getting item by name: TestItem" << std::endl;  // Debug log
//     EXPECT_EQ(inventory->getItem("TestItem"), item.get());
  // Expect the item to be returned
// }

// // Test getting a non-existing item by name
// TEST_F(InventoryTest, GetNonExistingItemByName) {
//     std::cout << "Getting non-existing item by name":"
//" NonExistentItem" << std::endl;  // Debug log
//     EXPECT_EQ(inventory->getItem("NonExistentItem"), nullptr);
  // Expect nullptr for non-existing item
// }

// // Test listing items in the inventory when it is empty
// TEST_F(InventoryTest, ListItemsEmptyInventory) {
//     testing::internal::CaptureStdout();  // Capture the output to test
//     inventory->listItems();  // List items (expect an empty inventory)
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "Your inventory is empty.\n");
  // Expect the appropriate empty message
// }

// // Test listing items in the inventory with items
// TEST_F(InventoryTest, ListItemsWithInventory) {
//     std::unique_ptr<TestItem> item1 =
// std::make_unique<TestItem>("TestItem1");
//     std::unique_ptr<TestItem> item2 =
// std::make_unique<TestItem>("TestItem2");
//     inventory->addItem(item1.get());  // Add items to inventory
//     inventory->addItem(item2.get());

//     testing::internal::CaptureStdout();  // Capture the output to test
//     inventory->listItems();  // List items in the inventory
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_TRUE(output.find("TestItem1") != std::string::npos);
  // Test for item1 in the output
//     EXPECT_TRUE(output.find("TestItem2") != std::string::npos);
  // Test for item2 in the output
// }
