// #include <gtest/gtest.h>
// #include "OxygenTank.hpp"
// #include "Player.hpp"
// #include "Game.hpp"

// // Mock Game class for Player constructor
// class MockGame : public Game {
//  public:
//     void gameOver(const std::string& message) override {}
// };

// class OxygenTankTest : public ::testing::Test {
//  protected:
//     OxygenTankTest() {
//         game = new MockGame();
//         player = new Player("Test Player", game);
//         oxygenTank = new OxygenTank();
//     }

//     ~OxygenTankTest() {
//         delete player;
//         delete game;
//         delete oxygenTank;
//     }

//     Player* player;
//     MockGame* game;
//     OxygenTank* oxygenTank;
// };

// TEST_F(OxygenTankTest, TestOxygenTankName) {
//     EXPECT_EQ(oxygenTank->getName(), "Oxygen Tank");
// }

// TEST_F(OxygenTankTest, TestUseOxygenTank) {
//     int initialOxygen = player->oxygenLevel;
//     oxygenTank->use(player);
//     EXPECT_EQ(player->oxygenLevel, initialOxygen + 20);
// }

// TEST_F(OxygenTankTest, TestUseOxygenTankNoException) {
//     EXPECT_NO_THROW(oxygenTank->use(player));
// }
