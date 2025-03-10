// #include <gmock/gmock.h>
// #include <gtest/gtest.h>

// #include "CoordinateMap.hpp"
// #include "DialogueManager.hpp"
// #include "Player.hpp"
// #include "Puzzle.hpp"
// #include "Quest.hpp"

// // Mock classes for dependencies
// class MockPuzzle : public Puzzle {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   MOCK_METHOD(bool, attempt, (), (override));
// };

// class MockPlayer : public Player {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   MOCK_METHOD(void, pickUp, (Item * item), (override));
// };

// class MockDialogueManager : public DialogueManager {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//   MOCK_METHOD
//(void, displayMessage, (const std::string& message), (override));
//   MOCK_METHOD(int, getChoice, (const std::string& prompt, int min, int max),
//               (override));
// };

// // Test Fixture
// class QuestTest : public ::testing::Test {
//  protected:
//   Quest* quest;
//   MockPuzzle* mockPuzzle;
//   MockPlayer* mockPlayer;
//   MockDialogueManager* mockDialogueManager;

//   void SetUp() override {
//     mockPuzzle = new MockPuzzle();
//     mockPlayer = new MockPlayer();
//     mockDialogueManager = new MockDialogueManager();
//     quest = new Quest("Test Quest", mockPuzzle,
//                       mockDialogueManager);
// Assuming constructor is updated
//   }

//   void TearDown() override {
//     delete quest;
//     delete mockPuzzle;
//     delete mockPlayer;
//     delete mockDialogueManager;
//   }
// };

// // Test for constructor
// TEST_F(QuestTest, ConstructorTest) {
//   EXPECT_EQ(quest->getDescription(), "Test Quest");
//   EXPECT_FALSE(quest->isCompleted());
// }

// // Test for attempt method - success case
// TEST_F(QuestTest, AttemptSuccess) {
//   EXPECT_CALL(*mockPuzzle, attempt()).WillOnce(testing::Return(true));
//   EXPECT_CALL(*mockPlayer, pickUp(testing::NotNull()));
//   EXPECT_CALL(*mockDialogueManager,
//               getChoice("Choose how to interpret the patterns:\n1. Morse "
//                         "Code\n2. Binary Coordinates",
//                         1, 2))
//       .WillOnce(testing::Return(2));

//   bool result = quest->attempt(mockPlayer);
//   EXPECT_TRUE(result);
//   EXPECT_TRUE(quest->isCompleted());
// }

// // Test for attempt method - failure case (wrong choice)
// TEST_F(QuestTest, AttemptFailureWrongChoice) {
//   EXPECT_CALL(*mockPuzzle, attempt()).Times(0);  // Should not be called
//   EXPECT_CALL(*mockDialogueManager,
//               getChoice("Choose how to interpret the patterns:\n1. Morse "
//                         "Code\n2. Binary Coordinates",
//                         1, 2))
//       .WillOnce(testing::Return(1));

//   bool result = quest->attempt(mockPlayer);
//   EXPECT_FALSE(result);
//   EXPECT_FALSE(quest->isCompleted());
// }

// // Test for attempt method - failure case (puzzle failure)
// TEST_F(QuestTest, AttemptFailurePuzzle) {
//   EXPECT_CALL(*mockPuzzle, attempt()).WillOnce(testing::Return(false));
//   EXPECT_CALL(*mockDialogueManager,
//               getChoice("Choose how to interpret the patterns:\n1. Morse "
//                         "Code\n2. Binary Coordinates",
//                         1, 2))
//       .WillOnce(testing::Return(2));

//   bool result = quest->attempt(mockPlayer);
//   EXPECT_FALSE(result);
//   EXPECT_FALSE(quest->isCompleted());
// }

// // Test for displayQuestInfo
// TEST_F(QuestTest, DisplayQuestInfo) {
//   std::ostringstream output;
//   std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

//   quest->displayQuestInfo();

//   std::cout.rdbuf(oldCoutBuffer);  // Restore original buffer
//   EXPECT_EQ(output.str(), "Quest: Test Quest (Incomplete)\n");
// }

// // Test for displayQuestInfo after completion
// TEST_F(QuestTest, DisplayQuestInfoAfterCompletion) {
//   EXPECT_CALL(*mockPuzzle, attempt()).WillOnce(testing::Return(true));
//   EXPECT_CALL(*mockPlayer, pickUp(testing::NotNull()));
//   EXPECT_CALL(*mockDialogueManager,
//               getChoice("Choose how to interpret the patterns:\n1. Morse "
//                         "Code\n2. Binary Coordinates",
//                         1, 2))
//       .WillOnce(testing::Return(2));

//   quest->attempt(mockPlayer);  // Complete the quest

//   std::ostringstream output;
//   std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

//   quest->displayQuestInfo();

//   std::cout.rdbuf(oldCoutBuffer);  // Restore original buffer
//   EXPECT_EQ(output.str(), "Quest: Test Quest (Completed)\n");
// }

// // Main function for running tests
// int main(int argc, char** argv) {
//   ::testing::InitGoogleMock(&argc, argv);
//   return RUN_ALL_TESTS();
// }
