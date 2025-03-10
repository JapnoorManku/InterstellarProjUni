#include <gtest/gtest.h>
#include "NPC.hpp"
#include "Player.hpp"
#include "Game.hpp"

// Dummy Game class for testing purposes
class DummyGame : public Game {
 public:
    DummyGame() : Game() {} // Use the base Game constructor
};

// Dummy Player class for testing purposes
class DummyPlayer : public Player {
 public:
    DummyPlayer(const std::string& name)
        : Player(name, &dummyGame) {}  // Pass a DummyGame object

 private:
    DummyGame dummyGame;  // Dummy Game object to pass to Player
};

// A derived class for testing, implements the pure virtual interact function
class TestNPC : public NPC {
 public:
    TestNPC(const std::string& name) : NPC(name) {}

    void interact(Player* player) override {
        // A simple implementation for the test
        (void)player;  // Prevent unused variable warning
    }
};

// Test fixture for NPC class
class NPCTest : public ::testing::Test {
 protected:
    TestNPC* npc;
    DummyPlayer* player;

    void SetUp() override {
        npc = new TestNPC("TestNPC");
        player = new DummyPlayer("TestPlayer");
    }

    void TearDown() override {
        delete npc;
        delete player;
    }
};

// Test NPC Constructor
TEST_F(NPCTest, ConstructorInitializesName) {
    EXPECT_EQ(npc->getName(), "TestNPC");
}

// Test interact Method (Basic interaction validation)
TEST_F(NPCTest, InteractDoesNotThrow) {
    EXPECT_NO_THROW(npc->interact(player));  // Interact with the dummy player
}
