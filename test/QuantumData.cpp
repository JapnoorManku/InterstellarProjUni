// #include "gtest/gtest.h"
// #include "QuantumData.hpp"
// #include "DialogueManager.hpp"
// #include "Player.hpp"


// class MockDialogueManager : public DialogueManager {
//  public:
//   static void displayMessage(const std::string& message) {
//     capturedMessage = message;
//   }

//   static std::string capturedMessage;
// };

// class MockPlayer : public Player {
//  public:
//   MockPlayer(const std::string& name, Game* game) : Player(name, game) {}
// };


// class QuantumDataTest : public ::testing::Test {
//  protected:
//   QuantumDataTest() {
//     quantumData = new QuantumData();
//     player = new MockPlayer("Test Player", nullptr);
//   }

//   ~QuantumDataTest() {
//     delete quantumData;
//     delete player;
//   }

//   QuantumData* quantumData;
//   MockPlayer* player;
// };


// TEST_F(QuantumDataTest, TestUseQuantumData) {
//   MockDialogueManager::capturedMessage.clear();

//   quantumData->use(player);

//   EXPECT_EQ(MockDialogueManager::capturedMessage,
//             "You analyze the Quantum Data"
// "and gain profound insights into the "
//             "universe.");
// }
