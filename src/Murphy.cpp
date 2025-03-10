/**
 * @file Murphy.cpp
 * @brief Implements the Murphy class methods.
 */

#include "Murphy.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"
#include "Game.hpp"
#include "NASAHeadquarters.hpp"
#include "Puzzle.hpp"
#include "CoordinateMap.hpp"

Murphy::Murphy() : NPC("Murphy") {}

void Murphy::interact(Player* player) {
    if (!player->hasItem("Coordinate Map")) {
        // Initial interaction with Murphy
        DialogueManager::displayMessage(
            "Murphy: \"Dad! The sand lines on"
             "the floor... they're a message. Decode them!\"");

        // Create a binary puzzle
        std::vector<std::string> binaryLines =
         {"01001101", "01001000"};  // Example binary lines
        std::pair<int, int> correctCoordinates =
         {77, 72};  // Example correct coordinates
        Puzzle sandPuzzle(
            "Decode the binary coordinates to find NASA's location.",
            binaryLines,
            correctCoordinates);

        // Attempt the puzzle
        if (sandPuzzle.attempt()) {
            // Puzzle solved
            DialogueManager::displayMessage
            ("Murphy: \"You did it! You found the coordinates.\"");

            // Add the Coordinate Map to the player's inventory
            player->getInventory()->addItem(new CoordinateMap());

            // Next step dialogue
            DialogueManager::displayMessage(
                "Murphy: \"We have the coordinates."
                 "Should we see where they lead us?\"");
            char choice = DialogueManager::getYesNo
            ("Do you want to go to the location?");

            if (choice == 'Y') {
                // Proceed to NASA Headquarters
                NASAHeadquarters* nasaHQ = new NASAHeadquarters();

                // Set exits between current location and NASA HQ
                player->getCurrentLocation()->
                setExit("NASA Headquarters", nasaHQ);
                nasaHQ->setExit(player->getCurrentLocation()->
                getName(), player->getCurrentLocation());

                player->move(nasaHQ);
            } else {
                DialogueManager::displayMessage
                ("Murphy: \"Okay, maybe later.\"");
            }
        } else {
            // Puzzle failed
            DialogueManager::displayMessage
            ("Murphy: \"No! That wasn’t right...\"");
            player->getGame()->gameOver("Failed to decode the sand lines.");
        }
    } else {
        // Interaction after obtaining the Coordinate Map
        DialogueManager::displayMessage(
            "Murphy: \"We have the coordinates."
             "Should we see where they lead us?\"");
        char choice = DialogueManager::getYesNo
        ("Do you want to go to the location?");
        if (choice == 'Y') {
            // Proceed to NASA Headquarters
            NASAHeadquarters* nasaHQ = new NASAHeadquarters();

            // Set exits between current location and NASA HQ
            player->getCurrentLocation()->setExit("NASA Headquarters", nasaHQ);
            nasaHQ->setExit(player->getCurrentLocation()->
            getName(), player->getCurrentLocation());

            player->move(nasaHQ);
        } else {
            DialogueManager::displayMessage("Murphy: \"Okay, maybe later.\"");
        }
    }
}
