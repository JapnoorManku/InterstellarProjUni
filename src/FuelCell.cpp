/**
 * @file FuelCell.cpp
 * @brief Implements the FuelCell class methods.
 */

#include <iostream>
#include "FuelCell.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"

FuelCell::FuelCell() : Item("Fuel Cell") {}

void FuelCell::use(Player* player) {
  DialogueManager::displayMessage("Using " + getName() +
  ": Your spacecraft is refueled and ready for the journey.");
  // Additional logic for using the Fuel Cell can be implemented here
}
