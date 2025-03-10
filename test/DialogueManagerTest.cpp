// #include <gtest/gtest.h>
// #include <gmock/gmock.h>
// #include "DialogueManager.hpp"

// // Test for the DialogueManager class
// class DialogueManagerTest : public ::testing::Test {
// protected:
//     // Helper function to simulate user input (mocking std::cin)
//     void mockInput(const std::string& input) {
//         std::istringstream inputStream(input);
//         std::cin.rdbuf(inputStream.rdbuf());
//     }
// };

// // Test for displaying a message
// TEST_F(DialogueManagerTest, TestDisplayMessage) {
//     // Capture std::cout output
//     std::ostringstream output;
//     std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

//     DialogueManager::displayMessage("Test message");

//     // Check if the correct message was displayed
//     EXPECT_EQ(output.str(), "Test message\n");

//     // Restore std::cout
//     std::cout.rdbuf(originalBuffer);
// }

// // Test for getting a yes/no input (valid case)
// TEST_F(DialogueManagerTest, TestGetYesNoValid) {
//     // Simulate valid input "Y"
//     mockInput("Y\n");

//     // Run the method and check if the result is 'Y'
//     EXPECT_EQ(DialogueManager::getYesNo("Do you agree?"), 'Y');
// }

// // Test for getting a yes/no input (invalid case)
// TEST_F(DialogueManagerTest, TestGetYesNoInvalid) {
//     // Simulate invalid input, then a valid one
//     mockInput("X\nY\n");

//     // Check that the method eventually returns 'Y' after invalid input
//     EXPECT_EQ(DialogueManager::getYesNo("Do you agree?"), 'Y');
// }

// // Test for getting a valid choice
// TEST_F(DialogueManagerTest, TestGetChoiceValid) {
//     // Simulate valid input "2"
//     mockInput("2\n");

//     // Run the method and check if the choice is correct
//     EXPECT_EQ(DialogueManager::getChoice("Choose an option: ", 1, 3), 2);
// }

// // Test for getting an invalid choice
// TEST_F(DialogueManagerTest, TestGetChoiceInvalid) {
//     // Simulate invalid input, then a valid one
//     mockInput("5\n2\n");

//     // Check that the method eventually returns the valid choice
//     EXPECT_EQ(DialogueManager::getChoice("Choose an option: ", 1, 3), 2);
// }

// // Test for getting a string input
// TEST_F(DialogueManagerTest, TestGetInput) {
//     // Simulate input "Test input"
//     mockInput("Test input\n");

//     // Check if the input matches what was entered
//     EXPECT_EQ(DialogueManager::getInput("Enter something: "), "Test input");
// }
