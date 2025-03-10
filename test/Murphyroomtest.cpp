// #include <gtest/gtest.h>
// #include "CoopersHouse.hpp"
// #include "CoordinateMap.hpp"
// #include "DialogueManager.hpp"
// #include "Game.hpp"
// #include "Murphy.hpp"
// #include "MurphyRoom.hpp"
// #include "Player.hpp"

// class MockPlayer : public Player {
//  public:
//   Environment* movedTo;
//   bool hasCoordinateMap = false;
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//  public:
//   Environment* movedTo;
//   bool hasCoordinateMap = false;
//   MockPlayer() : Player("Test Player", nullptr) {}

//   void move(Environment* environment) { movedTo = environment; }
// };

// class MockGame : public Game {
//  public:
//   Environment* movedTo;
//   bool hasCoordinateMap = false;
//   void gameOver(const std::string& reason) {}
// };

// class MurphyRoomTest : public ::testing::Test {
//  protected:
//   MurphyRoomTest() {
//     coopersHouse = new CoopersHouse();
//     murphyRoom = new MurphyRoom(coopersHouse);
//     player = new MockPlayer();
//   }

//   ~MurphyRoomTest() {
//     delete coopersHouse;
//     delete murphyRoom;
//     delete player;
//   }

//   MurphyRoom* murphyRoom;
//   MockPlayer* player;
//   CoopersHouse* coopersHouse;
// };

// TEST_F(MurphyRoomTest, TestEnterMurphyRoom) {
//   testing::internal::CaptureStdout();

//   murphyRoom->enter(player);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("You are in Murphy's Room."), std::string::npos);
// }

// TEST_F(MurphyRoomTest, TestInteractWithMurphy) {
//   testing::internal::CaptureStdout();

//   player->setHasCoordinateMap(false);
//   murphyRoom->enter(player);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("Talk to Murphy"), std::string::npos);
// }

// TEST_F(MurphyRoomTest, TestReturnToCoopersHouse) {
//   testing::internal::CaptureStdout();

//   murphyRoom->enter(player);
//   player->move(coopersHouse);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("You are now in Cooper's House"), std::string::npos);
// }

// TEST_F(MurphyRoomTest, TestMainRoomSubLocation) {
//   EXPECT_EQ(murphyRoom->getCurrentSubLocation(), "MainRoom");
// }

// TEST_F(MurphyRoomTest, TestExplorationChoiceTalkToMurphy) {
//   testing::internal::CaptureStdout();

//   player->setHasCoordinateMap(false);
//   murphyRoom->enter(player);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("Talk to Murphy"), std::string::npos);
// }

// TEST_F(MurphyRoomTest, TestTalkToMurphyNoMap) {
//   testing::internal::CaptureStdout();

//   player->setHasCoordinateMap(false);
//   murphyRoom->enter(player);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("Murphy: \"Dad! The sand lines on the floor..."),
//             std::string::npos);
// }

// TEST_F(MurphyRoomTest, TestTalkToMurphyWithMap) {
//   testing::internal::CaptureStdout();

//   player->setHasCoordinateMap(true);
//   murphyRoom->enter(player);

//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_NE(output.find("Murphy: \"We have the coordinates."),
//             std::string::npos);
// }


// MurphyRoomTest.cpp

// #include "gtest/gtest.h"
// #include "Player.hpp"
// #include "Environment.hpp"
// #include "Game.hpp"
// #include "Inventory.hpp"

// // Mock Classes
// class TestEnvironment : public Environment {
// public:
//     void enter(Player* player) override {}
//     void exploreLocations(Player* player) override {}
//     std::string getDescription() const override {
//         return "Test Environment";
//     }
// };

// class TestGame : public Game {
// public:
//     bool isGameOver() const override {
//         return gameOver_;
//     }

//     std::string getGameOverReason() const override {
//         return gameOverReason_;
//     }

// private:
//     bool gameOver_ = false;
//     std::string gameOverReason_ = "No reason";
// };

// // Test Fixture
// class MurphyRoomTest : public ::testing::Test {
// protected:
//     Player* player;
//     TestGame* game;

//     void SetUp() override {
//         game = new TestGame();
//         player = new Player("TestPlayer", game);
//     }

//     void TearDown() override {
//         delete player;
//         delete game;
//     }
// };

// TEST_F(MurphyRoomTest, MoveToMurphyRoom) {
//     TestEnvironment* murphyRoom = new TestEnvironment();
//     player->move(murphyRoom);
//     EXPECT_EQ(player->getCurrentLocation(), murphyRoom);
//     delete murphyRoom;
// }

// TEST_F(MurphyRoomTest, CheckPlayerStatus) {
//     player->checkStatus();
//     SUCCEED(); // Verify no crashes or exceptions
// }
