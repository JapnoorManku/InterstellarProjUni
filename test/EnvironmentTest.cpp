#include <gtest/gtest.h>
#include "Environment.hpp"
#include "NPC.hpp"
#include "Item.hpp"

// Concrete subclass of Environment for testing purposes
class TestEnvironment : public Environment {
 public:
  TestEnvironment(const std::string& name) : Environment(name) {}

  // Implement pure virtual functions for testing
  void enter(Player* player) override {
    (void)player; // Avoid unused parameter warning
  }

  void exploreLocations(Player* player) override {
    (void)player; // Avoid unused parameter warning
  }

  std::string getDescription() const override {
    return "Test environment description.";
  }
};

// Concrete subclass of NPC for testing purposes
class TestNPC : public NPC {
 public:
  TestNPC(const std::string& name) : NPC(name) {}

  void interact(Player* player) override {
    (void)player; // Avoid unused parameter warning
  }
};

// Concrete subclass of Item for testing purposes
class TestItem : public Item {
 public:
  TestItem(const std::string& name) : Item(name) {}

  void use(Player* player) override {
    (void)player; // Avoid unused parameter warning
  }
};

// Test fixture for Environment class
class EnvironmentTest : public ::testing::Test {
 protected:
  TestEnvironment* environment;

  void SetUp() override {
    environment = new TestEnvironment("TestEnvironment");
  }

  void TearDown() override {
    delete environment;
      // The environment's destructor will clean up NPCs, items, etc.
  }
};

// Test Constructor
TEST_F(EnvironmentTest, ConstructorInitializesName) {
  EXPECT_EQ(environment->getName(), "TestEnvironment");
}

// Test Adding and Retrieving SubLocations
TEST_F(EnvironmentTest, AddAndRetrieveSubLocations) {
  environment->addSubLocation("Cave");
  environment->addSubLocation("Forest");

  environment->setCurrentSubLocation("Cave");
  EXPECT_EQ(environment->getCurrentSubLocation(), "Cave");

  environment->setCurrentSubLocation("Forest");
  EXPECT_EQ(environment->getCurrentSubLocation(), "Forest");
}

// Test Adding and Retrieving NPCs
TEST_F(EnvironmentTest, AddAndRetrieveNPCs) {
  TestNPC* npc1 = new TestNPC("Guard");
  TestNPC* npc2 = new TestNPC("Merchant");

  environment->addSubLocation("Village");
  environment->setCurrentSubLocation("Village");

  environment->addNPC("Village", npc1);
  environment->addNPC("Village", npc2);

  auto npcs = environment->getNPCsInCurrentSubLocation();
  ASSERT_EQ(npcs.size(), 2);
  EXPECT_EQ(npcs[0]->getName(), "Guard");
  EXPECT_EQ(npcs[1]->getName(), "Merchant");
  // No need to manually delete
  //NPCs since Environment's destructor will handle it
}

// Test Adding and Retrieving Items
TEST_F(EnvironmentTest, AddAndRetrieveItems) {
  TestItem* item1 = new TestItem("Sword");
  TestItem* item2 = new TestItem("Shield");

  environment->addSubLocation("Armory");
  environment->setCurrentSubLocation("Armory");

  environment->addItem("Armory", item1);
  environment->addItem("Armory", item2);

  auto items = environment->getItemsInCurrentSubLocation();
  ASSERT_EQ(items.size(), 2);
  EXPECT_EQ(items[0]->getName(), "Sword");
  EXPECT_EQ(items[1]->getName(), "Shield");
  // No need to manually delete
  //items since Environment's destructor will handle it
}

// Test Adding and Retrieving Exits
TEST_F(EnvironmentTest, AddAndRetrieveExits) {
  TestEnvironment* forest = new TestEnvironment("Forest");
  TestEnvironment* cave = new TestEnvironment("Cave");

  environment->setExit("north", forest);
  environment->setExit("south", cave);

  auto exits = environment->getExits();
  EXPECT_EQ(exits.size(), 2);
  EXPECT_EQ(exits.at("north")->getName(), "Forest");
  EXPECT_EQ(exits.at("south")->getName(), "Cave");
  // No need to manually delete exits
  //since Environment's destructor will handle it
}

// Test Retrieving NPCs When No NPCs Are Present
TEST_F(EnvironmentTest, GetNPCsWhenNonePresent) {
  environment->addSubLocation("EmptyArea");
  environment->setCurrentSubLocation("EmptyArea");

  auto npcs = environment->getNPCsInCurrentSubLocation();
  EXPECT_TRUE(npcs.empty());
}

// Test Retrieving Items When No Items Are Present
TEST_F(EnvironmentTest, GetItemsWhenNonePresent) {
  environment->addSubLocation("EmptyStorage");
  environment->setCurrentSubLocation("EmptyStorage");

  auto items = environment->getItemsInCurrentSubLocation();
  EXPECT_TRUE(items.empty());
}
