#include <gtest/gtest.h>
#include "Item.hpp"
#include "Player.hpp"

// Test class for the Item class
class ItemTest : public ::testing::Test {
 protected:
  class TestItem : public Item {
   public:
    TestItem(const std::string& name) : Item(name), useCalled(false) {}

    void use(Player* player) override {
      (void)player;  // Avoid unused parameter warning
      useCalled = true;  // Set the flag to true when the use method is called
    }

    bool wasUseCalled() const { return useCalled; }

   private:
    bool useCalled;  // Flag to track if 'use' method was called
  };

  TestItem* testItem;
  Player* testPlayer;

  void SetUp() override {
    testItem = new TestItem("TestItem");
    testPlayer = new Player("TestPlayer", nullptr);
  }

  void TearDown() override {
    delete testItem;
    delete testPlayer;
  }
};

// Test the 'use' method
TEST_F(ItemTest, UseMethodSetsFlag) {
  // Initially, the flag should be false
  EXPECT_FALSE(testItem->wasUseCalled());

  // Call the use method
  testItem->use(testPlayer);

  // After calling use, the flag should be set to true
  EXPECT_TRUE(testItem->wasUseCalled());
}
