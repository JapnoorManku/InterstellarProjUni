/**
 * @file Earth.cpp
 * @brief Implements the Earth class methods.
 */

#include <iostream>
#include "Earth.hpp"
#include "DialogueManager.hpp"
#include "Player.hpp"

Earth::Earth() : Environment("Earth") {
  addSubLocation("Surface");
  setCurrentSubLocation("Surface");
}

void Earth::enter(Player* player) {
  DialogueManager::displayMessage
  ("You are on Earth. There's nothing of interest here.");
  // No exploration needed, so we won't call exploreLocations here.
}

std::string Earth::getDescription() const {
  return "A barren surface of Earth, with nothing notable to do.";
}

void Earth::exploreLocations(Player* player) {
  DialogueManager::displayMessage("There's nothing to explore here.");
}
