#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Dialogue.hpp"
#include "DialogueManager.hpp"

// Test for the Dialogue class
class DialogueTest : public ::testing::Test {
 protected:
    Dialogue* dialogue;

    // Create a new Dialogue object before each test
    void SetUp() override {
        std::vector<std::string> options = {"Help", "Ignore", "Accept"};
        dialogue = new Dialogue("NPC", options, 3);
          // Correct option is 3 ("Accept")
    }

    // Clean up after each test
    void TearDown() override {
        delete dialogue;
    }
};

// Test for correct dialogue engagement
TEST_F(DialogueTest, TestEngageCorrect) {
    // Simulate user input choosing the correct option (3)
    std::istringstream input("3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(dialogue->engage());
}

// Test for incorrect dialogue engagement
TEST_F(DialogueTest, TestEngageIncorrect) {
    // Simulate user input choosing an incorrect option (2)
    std::istringstream input("2\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(dialogue->engage());
}
