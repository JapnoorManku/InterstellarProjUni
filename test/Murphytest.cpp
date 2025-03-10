// #include <gtest/gtest.h>

// #include <iostream>
// #include <string>
// #include <vector>

// #include "DialogueManager.hpp"
// #include "Game.hpp"
// #include "Murphy.hpp"
// #include "NASAHeadquarters.hpp"
// #include "Player.hpp"
// #include "Puzzle.hpp"
// #include "Quest.hpp"


// class MockGame : public Game {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   void gameOver(const std::string& message) { gameOverMessage = message; }

//   std::string getGameOverMessage() const { return gameOverMessage; }

//  private:
//   std::string gameOverMessage;
// };

// class MockDialogueManager : public DialogueManager {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   static void displayMessage(const std::string& message) {
//     messages.push_back(message);
//   }

//   static char getYesNo(const std::string& prompt) { return 'Y'; }

//   static std::vector<std::string> messages;
// };

// std::vector<std::string> MockDialogueManager::messages;

// class MockPlayer : public Player {
//  public:
//   bool hasCoordinateMap = false;
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }

//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   MockPlayer(Game* game) : Player("Test Player", game) {}

//   bool hasItem(const std::string& itemName) {
//     return itemName == "Coordinate Map";
//   }

//   void addItem(const std::string& itemName) {
//     if (itemName == "Coordinate Map") {
//       hasCoordinateMap = true;
//     }
//   }

//   bool hasCoordinateMap = false;

//  private:
//   Game* game;
// };

// class MurphyTest : public ::testing::Test {
//  protected:
//   MockGame* game;
//   MockPlayer* player;
//   Murphy* murphy;

//   void SetUp() override {
//     game = new MockGame();
//     player = new MockPlayer(game);
//     murphy = new Murphy();
//   }

//   void TearDown() override {
//     delete game;
//     delete player;
//     delete murphy;
//     MockDialogueManager::messages.clear();
//   }
// };

// TEST_F(MurphyTest, InteractionWithoutCoordinateMap) {
//   murphy->interact(player);

//   ASSERT_EQ(MockDialogueManager::messages.size(), 1);
//   ASSERT_EQ(MockDialogueManager::messages[0],
//             "Murphy: \"Dad! The sand lines on the floor..."
//             "they’re a message.Decode them !\"");
// }

// TEST_F(MurphyTest, InteractionWithCoordinateMap) {
//   player->addItem("Coordinate Map");

//   murphy->interact(player);

//   ASSERT_EQ(MockDialogueManager::messages.size(), 1);
//     ASSERT_EQ(MockDialogueManager::messages[0],
//               "Murphy: \"We have the coordinates."
//               "Should we see where they lead us?\"");
// }

// TEST_F(MurphyTest, FailedPuzzleAttempt) {
//   player->addItem("Wrong Item");

//   murphy->interact(player);

//   ASSERT_EQ(game->getGameOverMessage(), "Failed to decode the sand lines.");
// }

// TEST_F(MurphyTest, PuzzleSolvedSuccessfully) {
//   player->addItem("Coordinate Map");

//   murphy->interact(player);

//   ASSERT_EQ(MockDialogueManager::messages.size(), 2);
//   ASSERT_EQ(MockDialogueManager::messages[1],
//             "Murphy: \"You did it! You found the coordinates.\"");
// }



// MurphyTest.cpp

// #include "gtest/gtest.h"
// #include "Player.hpp"
// #include "Inventory.hpp"
// #include "Item.hpp"

// // Mock Classes
// class TestItem : public Item {
// public:
//     TestItem(const std::string& name) : name_(name) {}

//     std::string getName() const override {
//         return name_;
//     }

// private:
//     std::string name_;
// };

// class TestInventory : public Inventory {
// public:
//     void addItem(Item* item) override {
//         items.push_back(item);
//     }

//     Item* getItem(const std::string& name) const override {
//         for (const auto& item : items) {
//             if (item->getName() == name) {
//                 return item;
//             }
//         }
//         return nullptr;
//     }

//     void removeItem(Item* item) override {
//         items.erase(std::remove
//(items.begin(), items.end(), item), items.end());
//     }

//     void listItems() const override {
//         for (const auto& item : items) {
//             std::cout << item->getName() << std::endl;
//         }
//     }

// private:
//     std::vector<Item*> items;
// };

// // Test Fixture
// class MurphyTest : public ::testing::Test {
// protected:
//     Player* player;
//     TestInventory* inventory;
//     TestGame* game;

//     void SetUp() override {
//         game = new TestGame();
//         player = new Player("TestPlayer", game);
//         inventory = new TestInventory();
//     }

//     void TearDown() override {
//         delete player;
//         delete game;
//         delete inventory;
//     }
// };

// TEST_F(MurphyTest, AddAndRetrieveItem) {
//     TestItem* item = new TestItem("TestItem");
//     inventory->addItem(item);

//     EXPECT_EQ(inventory->getItem("TestItem"), item);

//     delete item;
// }

// TEST_F(MurphyTest, RemoveItem) {
//     TestItem* item = new TestItem("TestItem");
//     inventory->addItem(item);
//     inventory->removeItem(item);

//     EXPECT_EQ(inventory->getItem("TestItem"), nullptr);

//     delete item;
// }

// TEST_F(MurphyTest, ListItems) {
//     TestItem* item1 = new TestItem("Item1");
//     TestItem* item2 = new TestItem("Item2");
//     inventory->addItem(item1);
//     inventory->addItem(item2);

//     EXPECT_NO_THROW(inventory->listItems());

//     delete item1;
//     delete item2;
// }
