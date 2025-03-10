#include <gtest/gtest.h>
#include "Character.hpp"
#include "Player.hpp"

// Concrete subclass of Character for testing purposes
class TestCharacter : public Character {
 public:
  TestCharacter(const std::string& name) : Character(name) {}

  void interact(Player* player) override {
    // Simple interaction logic for testing
    (void)player; // Avoid unused parameter warning
  }
};

// Test fixture for Character class
class CharacterTest : public ::testing::Test {
 protected:
  TestCharacter* character;

  void SetUp() override {
    character = new TestCharacter("TestCharacter");
  }

  void TearDown() override {
    delete character;
  }
};

// Test Character Constructor
TEST_F(CharacterTest, ConstructorInitializesName) {
  EXPECT_EQ(character->getName(), "TestCharacter");
}

// Test getName Method
TEST_F(CharacterTest, GetNameReturnsCorrectName) {
  EXPECT_EQ(character->getName(), "TestCharacter");
}

// Test interact Method (Ensures no unexpected behavior)
TEST_F(CharacterTest, InteractDoesNotThrow) {
  Player* player = nullptr; // Using nullptr for simplicity
  EXPECT_NO_THROW(character->interact(player));
}
