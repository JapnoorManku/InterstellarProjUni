#include <gtest/gtest.h>
#include <gmock/gmock.h>  // Include gmock for mocking
#include "Puzzle.hpp"
#include "DialogueManager.hpp"

// Test for the Puzzle class
class PuzzleTest : public ::testing::Test {
 protected:
    Puzzle* puzzle;

    // Create a new Puzzle object before each test
    void SetUp() override {
        std::vector<std::string> binaryLines = {
            "010110", "011010", "100101"
        };
        puzzle = new Puzzle("Test Puzzle", binaryLines, {1, 1}, "CODE");
    }

    // Clean up after each test
    void TearDown() override {
        delete puzzle;
    }
};

// Test that the puzzle displays correctly
TEST_F(PuzzleTest, TestDisplayPuzzle) {
    // Redirect std::cout to capture the output
    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

    puzzle->display();

    std::string expectedOutput = "Test Puzzle\n010110\n011010\n100101\n";
    EXPECT_TRUE(output.str().find(expectedOutput) != std::string::npos);

    // Restore std::cout
    std::cout.rdbuf(originalBuffer);
}

// Test solving the puzzle with correct coordinates
TEST_F(PuzzleTest, TestAttemptCorrectCoordinates) {
    // Simulate user input for coordinates
    std::istringstream input("1 1\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(puzzle->attempt());
}

// Test solving the puzzle with incorrect coordinates
TEST_F(PuzzleTest, TestAttemptIncorrectCoordinates) {
    // Simulate user input for coordinates
    std::istringstream input("2 2\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(puzzle->attempt());
}

// Test solving the word-based puzzle correctly
TEST_F(PuzzleTest, TestAttemptWordCorrect) {
    // Simulate user input for word
    std::istringstream input("CODE\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(puzzle->attemptWord());
}

// Test solving the word-based puzzle incorrectly
TEST_F(PuzzleTest, TestAttemptWordIncorrect) {
    // Simulate user input for word
    std::istringstream input("WRONG\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(puzzle->attemptWord());
}
