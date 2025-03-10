/**
 * @file OxygenTank.cpp
 * @brief Implements the OxygenTank class methods.
 */

#include <iostream>
#include "OxygenTank.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"

OxygenTank::OxygenTank() : Item("Oxygen Tank") {}

void OxygenTank::use(Player* player) {
  player->increaseOxygen(20);
  DialogueManager::displayMessage
  ("Using " + getName() + ": Your oxygen level increases.");
}
