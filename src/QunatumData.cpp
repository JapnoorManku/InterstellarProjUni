/**
 * @file QuantumData.cpp
 * @brief Implements the QuantumData class methods.
 */

#include "QuantumData.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"

QuantumData::QuantumData() : Item("Quantum Data") {}

void QuantumData::use(Player* player) {
  DialogueManager::displayMessage
  ("You analyze the Quantum Data and gain "
  "profound insights into the universe.");
  // Additional logic...
}
