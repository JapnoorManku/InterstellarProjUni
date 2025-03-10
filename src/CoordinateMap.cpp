/**
 * @file CoordinateMap.cpp
 * @brief Implements the CoordinateMap class methods.
 */

#include <iostream>
#include "CoordinateMap.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"
#include "NASAHeadquarters.hpp"

CoordinateMap::CoordinateMap() : Item("Coordinate Map") {}

void CoordinateMap::use(Player* player) {
  DialogueManager::displayMessage("Using " + getName() +
  ": The map reveals NASA's location for further exploration.");
  // Logic handled in Murphy's interaction
}
