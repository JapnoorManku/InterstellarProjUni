/**
 * @file CoopersHouse.cpp
 * @brief Implements the CoopersHouse class methods.
 */

#include <iostream>
#include <string>
#include "CoopersHouse.hpp"
#include "DialogueManager.hpp"
#include "Player.hpp"
#include "MurphyRoom.hpp"

CoopersHouse::CoopersHouse() : Environment("Cooper's House") {
  addSubLocation("Living Room");
  addSubLocation("Second Floor");
  setCurrentSubLocation("Living Room");
}

void CoopersHouse::enter(Player* player) {
  DialogueManager::displayMessage
  ("You are in your house. It's quiet and calm.");
  exploreLocations(player);
}

std::string CoopersHouse::getDescription() const {
  if (currentSubLocation == "Living Room") {
    return "You are in the living room of your house.";
  } else if (currentSubLocation == "Second Floor") {
    return "You are on the second floor. Murphy's room is here.";
  }
  return "You are somewhere in your house.";
}

void CoopersHouse::exploreLocations(Player* player) {
  if (currentSubLocation == "Living Room") {
    DialogueManager::displayMessage("1. Go to Second Floor\n2. Look around");
    int choice = DialogueManager::getChoice("Choose an action: ", 1, 2);
    switch (choice) {
      case 1:
        setCurrentSubLocation("Second Floor");
        DialogueManager::displayMessage("You move to the Second Floor.");
        exploreLocations(player);
        break;
      case 2:
        DialogueManager::displayMessage
        ("You look around but find nothing of interest.");
        break;
    }
  } else if (currentSubLocation == "Second Floor") {
    DialogueManager::displayMessage
    ("1. Enter Murphy's Room\n2. Look around\n3. Go back to Living Room");
    int choice = DialogueManager::getChoice("Choose an action: ", 1, 3);
    switch (choice) {
      case 1: {
        // Create Murphy's Room if not already set
        if (exits.find("Murphy's Room") == exits.end()) {
          MurphyRoom* murphyRoom = new MurphyRoom(this);
          setExit("Murphy's Room", murphyRoom);
        }
        player->move(exits["Murphy's Room"]);
        break;
      }
      case 2:
        DialogueManager::displayMessage("You look around the second floor.");
        break;
      case 3:
        setCurrentSubLocation("Living Room");
        DialogueManager::displayMessage("You go back to the Living Room.");
        exploreLocations(player);
        break;
    }
  }
}
