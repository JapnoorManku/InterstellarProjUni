/**
 * @file MurphyRoom.cpp
 * @brief Implements the MurphyRoom class methods.
 */

#include <iostream>
#include <string>
#include "MurphyRoom.hpp"
#include "Murphy.hpp"
#include "CoordinateMap.hpp"
#include "DialogueManager.hpp"
#include "Player.hpp"

MurphyRoom::MurphyRoom(Environment* coopersHouse) : Environment
("Murphy's Room") {
  addSubLocation("MainRoom");
  setCurrentSubLocation("MainRoom");

  // Set exit back to Cooper's House
  setExit("Cooper's House", coopersHouse);

  // Add Murphy and Coordinate Map directly to MainRoom
  Murphy* murphy = new Murphy();
  addNPC("MainRoom", murphy);

  CoordinateMap* coordinateMap = new CoordinateMap();
  addItem("MainRoom", coordinateMap);
}

MurphyRoom::~MurphyRoom() {}

void MurphyRoom::enter(Player* player) {
  DialogueManager::displayMessage(getDescription());
  exploreLocations(player);
}

std::string MurphyRoom::getDescription() const {
  return "You are in Murphy's Room.";
}

void MurphyRoom::exploreLocations(Player* player) {
  DialogueManager::displayMessage
  ("1. Talk to Murphy\n2. Return to Cooper's House");
  int choice = DialogueManager::getChoice("Choose an action: ", 1, 2);
  switch (choice) {
    case 1: {
      auto npcsHere = getNPCsInCurrentSubLocation();
      if (!npcsHere.empty()) {
        npcsHere.front()->interact(player);
      } else {
        DialogueManager::displayMessage("There's nothing new here.");
      }
      break;
    }
    case 2:
      player->move(exits["Cooper's House"]);
      break;
  }
}
