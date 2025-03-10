/**
 * @file SpaceSuit.cpp
 * @brief Implements the SpaceSuit class methods.
 */

#include "SpaceSuit.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"

SpaceSuit::SpaceSuit() : Item("Space Suit") {}

void SpaceSuit::use(Player* player) {
  DialogueManager::displayMessage
  ("You put on the space suit, preparing for space travel.");
  // Additional logic...
}
