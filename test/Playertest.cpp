// #include <gtest/gtest.h>
// #include "Player.hpp"
// #include "NPC.hpp"

// // Test fixture for Player class
// class PlayerTest : public ::testing::Test {
// protected:
//     Player* player;

//     void SetUp() override {
//         player = new Player("TestPlayer", nullptr);
  // Mock Game passed as nullptr for testing
//     }

//     void TearDown() override {
//         delete player;
//     }
// };

// // Mock NPC class for testing
// class MockNPC : public NPC {
// public:
//     MockNPC(const std::string& name) : NPC(name) {}

//     // Override interact method to provide mock behavior
//     void interact(Player* player) override {
//         // Simulate interaction for testing purposes
//     }
// };

// // Test that Player constructor initializes the name correctly
// TEST_F(PlayerTest, ConstructorInitializesName) {
//     EXPECT_EQ(player->getName(), "TestPlayer");
// }

// // Test Player interacting with NPC (mocked)
// TEST_F(PlayerTest, InteractWithNPC) {
//     MockNPC* npc = new MockNPC("TestNPC");
//     EXPECT_NO_THROW(player->talkTo("TestNPC"));
//     delete npc;
// }

// // Test Player's health after taking damage
// TEST_F(PlayerTest, TakeDamageReducesHealth) {
//     int initialHealth = player->getHealth();
  // Assuming getHealth() is public or accessible via a getter

//     player->takeDamage(20);
//     EXPECT_EQ(player->getHealth(), initialHealth - 20);
  // Assuming the player starts with 100 health
// }

// // Test that Player's oxygen level increases correctly
// TEST_F(PlayerTest, OxygenLevelIncrease) {
//     int initialOxygen = player->getOxygenLevel();
  // Assuming getOxygenLevel() is public or accessible via a getter

//     player->increaseOxygen(10);
//     EXPECT_EQ(player->getOxygenLevel(), initialOxygen + 10);
  // Assuming oxygen doesn't exceed 100
// }
