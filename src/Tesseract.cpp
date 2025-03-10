#include <iostream>
#include "Tesseract.hpp"
#include "DialogueManager.hpp"
#include "Puzzle.hpp"
#include "Player.hpp"
#include "TesseractKey.hpp"
#include "Game.hpp"


Tesseract::Tesseract()
    : Environment("Tesseract"), puzzleSolved(false), timeShift(0) {}

void Tesseract::enter(Player* player) {
    DialogueManager::displayMessage(
        "You are now in the Tesseract."
         "The laws of time and space are twisted here.");
    DialogueManager::displayMessage(
        "You must solve a spatial puzzle to escape.");
    exploreLocations(player);  // Start exploring the Tesseract
}

std::string Tesseract::getDescription() const {
    return "The Tesseract is a 4-D space,"
     "where reality warps and time behaves unpredictably.\n";
}

void Tesseract::exploreLocations(Player* player) {
    while (!puzzleSolved) {
        DialogueManager::displayMessage(
            "To progress, you need to solve the puzzle inside the Tesseract.");
        DialogueManager::displayMessage(
            "You can: \n"
            "1. Attempt to solve the puzzle.\n"
            "2. Investigate the distortions in time and space.");

        int choice = DialogueManager::getChoice("Choose an action: ", 1, 2);

        switch (choice) {
            case 1:
                solvePuzzle(player);
                break;
            case 2:
                triggerSpatialShift();
                break;
            default:
                DialogueManager::displayMessage("Invalid choice. Try again.");
                break;
        }

        if (puzzleSolved) {
            DialogueManager::displayMessage(
                "You have solved the Tesseract puzzle."
                 "A portal opens, and the Tesseract collapses behind you.");

            // Add ASCII art ending
            std::cout << R"(
            ++++++++++++++++++++++++++++++++++++++++++++++++++++++
            +                                                    +
            +     ███████╗██╗   ██╗███╗   ██╗██╗███████╗         +
            +     ██╔════╝██║   ██║████╗  ██║██║██╔════╝         +
            +     █████╗  ██║   ██║██╔██╗ ██║██║███████╗         +
            +     ██╔══╝  ██║   ██║██║╚██╗██║██║╚════██║         +
            +     ██║     ╚██████╔╝██║ ╚████║██║███████║         +
            +     ╚═╝      ╚═════╝ ╚═╝  ╚═══╝╚═╝╚══════╝         +
            +                                                    +
            +            CONGRATULATIONS, YOU WON!               +
            +                                                    +
            +    Humanity's fate has been secured through your   +
            +      courage, intellect, and relentless spirit.    +
            +                                                    +
            ++++++++++++++++++++++++++++++++++++++++++++++++++++++
            )" << "\n";

            DialogueManager::displayMessage(
                "Thank you for playing! Humanity's"
                 "fate has been secured through your courage and intellect.");
            player->getGame()->gameOver("You won! The universe is saved.");
            return;  // Exit after winning
        }
    }
}



void Tesseract::solvePuzzle(Player* player) {
    DialogueManager::displayMessage(
        "You are attempting to solve the puzzle."
         "Decode the binary data into a word.");

    // Create a binary puzzle
    std::vector<std::string> binaryLines = {
        "01100011", "01101111", "01101111", "01110000", "01100101", "01110010"};
    std::string correctWord = "cooper";

    Puzzle* tesseractPuzzle = new Puzzle(
        "Solve the binary puzzle to decode a word:",
        binaryLines,
        {},  // No coordinates needed for word-based puzzles
        correctWord);

    bool success = tesseractPuzzle->attemptWord();
    // Attempt the word-based puzzle
    delete tesseractPuzzle;                         // Clean up the puzzle

    if (success) {
        DialogueManager::displayMessage(
            "You solved the Tesseract puzzle and unlocked the next dimension!");
        puzzleSolved = true;
        player->getInventory()->addItem(new TesseractKey());
    } else {
        DialogueManager::displayMessage(
            "You failed to solve the puzzle. The Tesseract collapses!");
        player->getGame()->gameOver
        ("The Tesseract imploded due to your failure.");
    }
}

void Tesseract::triggerSpatialShift() {
    timeShift += 10;  // Increase time shift counter
    DialogueManager::displayMessage(
        "The fabric of space is warping...");
    DialogueManager::displayMessage(
        "Time has shifted by " + std::to_string(timeShift) + " seconds!");
    DialogueManager::displayMessage(
        "You feel disoriented as your perception of time changes.");
}
