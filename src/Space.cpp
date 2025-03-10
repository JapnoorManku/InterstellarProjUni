/**
 * @file Space.cpp
 * @brief Implements the Space class methods.
 */

#include "Space.hpp"
#include "DialogueManager.hpp"
#include "Player.hpp"
#include "WaterPlanet.hpp"

// Constructor to setup the space environment
Space::Space() : Environment("Outer Space") {
  addSubLocation("Near Wormhole");
  addSubLocation("Out of Wormhole");
  setCurrentSubLocation("Near Wormhole");
}

// Destructor
Space::~Space() {}

// Method to enter the space environment
void Space::enter(Player* player) {
  DialogueManager::displayMessage("You are now in space, facing the Wormhole.");
  exploreLocations(player);  // Start the navigation task
}

// Description of the environment.
std::string Space::getDescription() const {
  return "Welcome to Space. Out here, possibilities are infinite and where "
         "dreams meet reality.";
}

// Method to handle the navigation task for the Wormhole
void Space::exploreLocations(Player* player) {
    bool inSpace = true;

    while (inSpace) {
        if (currentSubLocation == "Near Wormhole") {
            DialogueManager::displayMessage
            ("You have arrived at the Wormhole!");
            DialogueManager::displayMessage("Choose an action:");
            DialogueManager::displayMessage(
                "1. The only way through it"
                 "is to enter the correct sequence of "
                "commands to navigate.");

            int choice = DialogueManager::getChoice("Choose an action: ", 1, 1);

            if (choice == 1) {
                // Ask for the input
                DialogueManager::displayMessage(
                    "Enter in the correct"
                     "sequential order of navigational commands: "
                    "3,1,2 (excluding the commas and space)"
                     "to pass through the Wormhole "
                    "safely.");
                std::string input = DialogueManager::getInput
                ("Enter command sequence: ");

                // Check if the player entered the correct sequence
                if (input == "123") {
                    currentSubLocation = "Out of Wormhole";
                      // Update the sub-location
                    DialogueManager::displayMessage(
                        "Success! You have navigated through the Wormhole.");
                } else {
                    DialogueManager::displayMessage(
                        "Incorrect sequence!"
                         "You failed to navigate the Wormhole.");
                }
            }
        } else if (currentSubLocation == "Out of Wormhole") {
            DialogueManager::displayMessage(
                "Congratulations! The wormhole held, and so did you.\n"
                "This is a new galaxy, a new chapter in humanity's journey.\n");
            DialogueManager::displayMessage
            ("1. Move towards the Water Planet.");

            int nextAction = DialogueManager::getChoice
            ("Choose an action: ", 1, 1);

            if (nextAction == 1) {
                WaterPlanet* waterPlanet = new WaterPlanet();

                // Set the exit for seamless navigation
                setExit("Water Planet", waterPlanet);
                waterPlanet->setExit("Space", this);

                player->move(waterPlanet);// Move the player to the Water Planet
                inSpace = false;
                //Exit the loop after moving to the next environment
            }
        } else {
            DialogueManager::displayMessage(
                "You cannot move forward until the task is completed.");
        }
    }
}

