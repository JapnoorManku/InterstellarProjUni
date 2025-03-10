/**
 * @file NASAHeadquarters.cpp
 * @brief Implements the NASAHeadquarters class methods.
 */

#include "NASAHeadquarters.hpp"

#include <iostream>

#include "DialogueManager.hpp"
#include "DrBrand.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Space.hpp"
NASAHeadquarters::NASAHeadquarters()
    : Environment("NASA Headquarters"),
      fuelCount(0),
      gotJanitorFuel(false),
      gotColdRoomFuel(false),
      fuelQuestActive(false) {
  addSubLocation("Entrance");
  addSubLocation("Mission Control");
  addSubLocation("Basemeif (choice == 'Y') {nt");
  setCurrentSubLocation("Entrance");

  DrBrand* drBrand = new DrBrand();
  addNPC("Mission Control", drBrand);
}

void NASAHeadquarters::enter(Player* player) {
  DialogueManager::displayMessage("You arrive at NASA Headquarters.");
  exploreLocations(player);
}

std::string NASAHeadquarters::getDescription() const {
  if (currentSubLocation == "Entrance") {
    return "You are at the entrance of NASA Headquarters.";
  } else if (currentSubLocation == "Mission Control") {
    return "You are in the Mission Control room.";
  } else if (currentSubLocation == "Basement") {
    return "You are in the NASA basement, searching for rocket fuel.";
  }
  return "You are somewhere in NASA Headquarters.";
}

void NASAHeadquarters::exploreLocations(Player* player) {
    bool keepExploring = true;

    while (keepExploring) {
        if (!fuelQuestActive) {
            // Normal NASA HQ logic before starting the fuel quest
            if (currentSubLocation == "Entrance") {
                DialogueManager::displayMessage(
                    "1. Go to Mission Control\n"
                    "2. Look around\n"
                    "3. Return to Previous Location");

                int choice = DialogueManager::getChoice
                ("Choose an action: ", 1, 3);
                switch (choice) {
                    case 1:
                        setCurrentSubLocation("Mission Control");
                        DialogueManager::displayMessage
                        ("You proceed to Mission Control.");
                        break;
                    case 2:
                        DialogueManager::displayMessage(
                            "You look around but see nothing notable.");
                        break;
                    case 3:
                        if (exits.find("Previous Location") != exits.end()) {
                            player->move(exits["Previous Location"]);
                            return;  // Exit this method after moving
                        } else {
                            DialogueManager::displayMessage
                            ("You can't go back from here.");
                        }
                        break;
                    default:
                        DialogueManager::displayMessage
                        ("Invalid choice. Please try again.");
                        break;
                }
            } else if (currentSubLocation == "Mission Control") {
                DialogueManager::displayMessage(
                    "1. Talk to Dr. Brand\n"
                    "2. Look around\n"
                    "3. Return to Entrance");

                int choice = DialogueManager::getChoice
                ("Choose an action: ", 1, 3);
                switch (choice) {
                    case 1:
                        player->talkTo("Dr. Brand");
                        break;
                    case 2:
                        DialogueManager::displayMessage(
                            "You see various spacecraft"
                             "models and mission plans on the walls.");
                        break;
                    case 3:
                        setCurrentSubLocation("Entrance");
                        DialogueManager::displayMessage
                        ("You return to the entrance.");
                        break;
                    default:
                        DialogueManager::displayMessage
                        ("Invalid choice. Please try again.");
                        break;
                }
            }
        } else {
            // Fuel quest logic
            if (currentSubLocation != "Basement") {
                setCurrentSubLocation("Basement");
            }

            DialogueManager::displayMessage(
                "Where would you like to explore?\n"
                "1. Janitor's Room\n"
                "2. Conference Room\n"
                "3. Bathroom\n"
                "4. Cold room\n"
                "5. Return to NASA launchpad");

            int choice = DialogueManager::getChoice("Choose an action: ", 1, 5);

            switch (choice) {
                case 1:
                    if (!gotJanitorFuel) {
                        DialogueManager::displayMessage(
                            "You found a rocket fuel"
                             "container in the Janitor's Room!");
                        fuelCount++;
                        gotJanitorFuel = true;
                    } else {
                        DialogueManager::displayMessage
                        ("There's nothing new here.");
                    }
                    break;
                case 2:
                    DialogueManager::displayMessage(
                        "You found nothing in the Conference Room.");
                    break;
                case 3:
                    DialogueManager::displayMessage
                    ("You found nothing in the Bathroom.");
                    break;
                case 4:
                    if (!gotColdRoomFuel) {
                        DialogueManager::displayMessage(
                            "You found a rocket fuel"
                             "container in the Cold room!");
                        fuelCount++;
                        gotColdRoomFuel = true;
                    } else {
                        DialogueManager::displayMessage
                        ("There's nothing new here.");
                    }
                    break;
                case 5:
                    if (fuelCount < 2) {
                        DialogueManager::displayMessage(
                            "You don't have all the fuel needed to launch!");
                    } else {
                        DialogueManager::displayMessage(
                            "You have collected enough fuel."
                             "Let's proceed to launch!");
                        char confirmationChoice =
                            DialogueManager::getYesNo
                            ("Are you ready for the launch?");
                        if (confirmationChoice == 'Y') {
                            Space* spc = new Space();
                            setExit("Space", spc);
                            spc->setExit("NASA Headquarters", this);
                            player->move(spc);
                            keepExploring = false;
                            // Exit the loop after moving
                        } else {
                            DialogueManager::displayMessage
                            ("Let's take off later.");
                        }
                    }
                    break;
                default:
                    DialogueManager::displayMessage
                    ("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}


void NASAHeadquarters::startFuelQuest() {
  // Called after Dr. Brand gives permission and mission is accepted
  fuelQuestActive = true;
  setCurrentSubLocation("Basement");
}
