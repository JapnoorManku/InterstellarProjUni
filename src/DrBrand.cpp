/**
 * @file DrBrand.cpp
 * @brief Implements the DrBrand class methods.
 */

#include <iostream>
#include <vector>
#include "DrBrand.hpp"
#include "DialogueManager.hpp"
#include "Player.hpp"
#include "QuantumData.hpp"
#include "Game.hpp"
#include "NASAHeadquarters.hpp"

DrBrand::DrBrand() : NPC("Dr. Brand") {}

void DrBrand::interact(Player* player) {
  DialogueManager::displayMessage
  (name + ": \"You've decoded the coordinates, "
  "but are you ready for the mission?\"");

  std::vector<std::string> options = {
      "I have extensive experience as a pilot.",
      "I am committed to saving humanity.",
      "I don't think I'm the right person for this mission."
  };

  // Correct option index is 2 (second option)
  Dialogue dialogue(name, options, 2);
  bool success = dialogue.engage();

  if (success) {
    DialogueManager::displayMessage
    ("Dr. Brand: \"Welcome aboard the Endurance mission.\"");
    // Reward the player with Quantum Data
    player->pickUp(new QuantumData());
    // After success with Dr. Brand in DrBrand.cpp
    NASAHeadquarters* nasaHQ = dynamic_cast<NASAHeadquarters*>
    (player->getCurrentLocation());
    if (nasaHQ) {
  nasaHQ->startFuelQuest();
}
  } else {
    DialogueManager::displayMessage("Game Over: You were denied the mission.");
    player->getGame()->gameOver("You were denied the mission.");
  }
}
