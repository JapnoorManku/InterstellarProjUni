#include <iostream>
#include <bitset>
#include <sstream>
#include <ctime>
#include "Puzzle.hpp"
#include "DialogueManager.hpp"

// Constructor
Puzzle::Puzzle(const std::string& description,
               const std::vector<std::string>& binaryLines,
               const std::pair<int, int>& correctCoordinates,
               const std::string& correctWord)
    : description(description), binaryLines(binaryLines),
      correctCoordinates(correctCoordinates), correctWord(correctWord),
      isSolved(false) {}

// Display the puzzle
void Puzzle::display() const {
    DialogueManager::displayMessage(description);
    for (const auto& line : binaryLines) {
        DialogueManager::displayMessage(line);
    }
}

// Attempt to solve the numeric puzzle
bool Puzzle::attempt() {
    display();
    DialogueManager::displayMessage
    ("Decode the binary strings into decimal coordinates.");

    // Player input
    int x, y;
    std::cout << "Enter the X coordinate: ";
    std::cin >> x;
    std::cout << "Enter the Y coordinate: ";
    std::cin >> y;

    // Validate the coordinates
    if (std::make_pair(x, y) == correctCoordinates) {
        DialogueManager::displayMessage
        ("Correct! You decoded the coordinates successfully.");
        isSolved = true;
        return true;
    } else {
        DialogueManager::displayMessage("Incorrect coordinates. Game Over.");
        return false;
    }
}

// Attempt to solve the word-based puzzle
bool Puzzle::attemptWord() {
    display();
    DialogueManager::displayMessage("Decode the binary strings into a word.");

    // Player input
    std::string input;
    std::cout << "Enter the decoded word: ";
    std::cin >> input;

    // Validate the decoded word
    if (input == correctWord) {
        DialogueManager::displayMessage
        ("Correct! You decoded the word successfully.");
        isSolved = true;
        return true;
    } else {
        DialogueManager::displayMessage("Incorrect word. Game Over.");
        return false;
    }
}

// Solve navigational sequence
bool Puzzle::solveNavigationalSequence
(const std::vector<std::string>& correctSequence) {
    std::cout << "Input the sequence of navigational"
     "commands (e.g., Left, Right, Forward):\n";

    std::vector<std::string> playerInput;
    for (size_t i = 0; i < correctSequence.size(); ++i) {
        std::string command;
        std::cout << "Command " << i + 1 << ": ";
        std::cin >> command;
        playerInput.push_back(command);
    }

    if (playerInput == correctSequence) {
        std::cout << "Correct sequence!"
         "You navigated the wormhole successfully.\n";
        return true;
    } else {
        std::cout << "Incorrect sequence."
         "The ship is lost in the wormhole. Game Over.\n";
        return false;
    }
}

bool Puzzle::solveTimedSequence(int timeLimit, int requiredActions) {
    std::cout << "You have " << timeLimit
              << " seconds to complete " << requiredActions
              << " actions. Type 'Collect' to gather data.\n";

    int actionsCompleted = 0;
    std::time_t startTime = std::time(nullptr);  // Get the current time

    while (actionsCompleted < requiredActions) {
        std::string input;
        std::cout << "Action ("
         << actionsCompleted + 1 << "/" << requiredActions << "): ";
        std::cin >> input;

        if (input == "Collect") {
            ++actionsCompleted;
            std::time_t currentTime = std::time(nullptr);
            int elapsedTime = static_cast<int>(currentTime - startTime);

            // Check remaining time
            int remainingTime = timeLimit - elapsedTime;
            if (remainingTime <= 0) {
                std::cout << "Time is up!"
                 "The tidal wave destroyed the lander. Game Over.\n";
                return false;
            }

            std::cout << "Action completed! ("
             << actionsCompleted << "/" << requiredActions << ")\n";
            std::cout << "Time remaining: " << remainingTime << " seconds.\n";
        } else {
            std::cout << "Invalid action. Type 'Collect' to gather data.\n";
        }

        // Calculate elapsed time
        std::time_t currentTime = std::time(nullptr);
        int elapsedTime = static_cast<int>(currentTime - startTime);

        if (elapsedTime > timeLimit) {
            std::cout << "Time is up! The"
             "tidal wave destroyed the lander. Game Over.\n";
            return false;
        }
    }

    std::cout << "You successfully gathered"
     "the data and returned to the ship in time!\n";
    return true;
}



bool Puzzle::solveMorseCode
(const std::vector<std::pair<std::string, std::string>>& correctSequence) {
    std::cout << "Rearrange the data sequences"
     "into the correct Morse code order.\n";

    for (size_t i = 0; i < correctSequence.size(); ++i) {
        std::cout << i + 1 << ". " << correctSequence[i].first << "\n";
    }

    std::cout << "Input the correct sequence by number (e.g., 3 1 2): ";
    std::vector<int> playerSequence(correctSequence.size());
    for (size_t i = 0; i < correctSequence.size(); ++i) {
        std::cin >> playerSequence[i];
        --playerSequence[i]; // Convert to 0-based index
    }

    bool correct = true;
    for (size_t i = 0; i < correctSequence.size(); ++i) {
        if (correctSequence[playerSequence[i]].second
         != correctSequence[i].second) {
            correct = false;
            break;
        }
    }

    if (correct) {
        std::cout << "You successfully transmitted the Morse code!\n";
        return true;
    } else {
        std::cout << "Incorrect sequence."
         "Humanity's fate is sealed. Game Over.\n";
        return false;
    }
}
