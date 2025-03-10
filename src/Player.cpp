/**
 * @file Player.cpp
 * @brief Implements the Player class methods.
 */

#include <iostream>
#include "Player.hpp"
#include "DialogueManager.hpp"
#include "Game.hpp"

Player::Player(const std::string& name, Game* game)
    : Character(name), currentLocation(nullptr),
    health(100), oxygenLevel(100), game(game) {}

Player::~Player() {
  DialogueManager::displayMessage(name + " has left the game.");
}

Environment* Player::getCurrentLocation() const {
  return currentLocation;
}

// void Player::addItem(Item* item) {
//   inventory.push_back(item);
// }

void Player::move(Environment* newLocation) {
  if (newLocation && newLocation != currentLocation) {
    // Moving to a new environment
    currentLocation = newLocation;
    currentLocation->enter(this);
  } else if (currentLocation) {
    // Moving within the current environment
    currentLocation->exploreLocations(this);
  } else {
    DialogueManager::displayMessage("You are nowhere. This shouldn't happen.");
  }
}

void Player::interact(Player* other) {
  DialogueManager::displayMessage(name +
  " cannot directly interact with another player.");
}

void Player::useItem(const std::string& itemName) {
  Item* item = inventory.getItem(itemName);
  if (item) {
    item->use(this);
  } else {
    DialogueManager::displayMessage("You do not have "
    + itemName + " in your inventory.");
  }
}

bool Player::hasItem(const std::string& itemName) const {
  return inventory.getItem(itemName) != nullptr;
}

void Player::talkTo(const std::string& npcName) {
  if (!currentLocation) {
    DialogueManager::displayMessage("You are not in any location.");
    return;
  }

  auto npcsHere = currentLocation->getNPCsInCurrentSubLocation();
  for (auto npc : npcsHere) {
    if (npc->getName() == npcName) {
      npc->interact(this);
      return;
    }
  }

  DialogueManager::displayMessage
  ("There is no one named " + npcName + " here.");
}

void Player::checkStatus() const {
  DialogueManager::displayMessage
  ("Status of " + name + ":\nHealth: " + std::to_string(health) +
                "\nOxygen Level: " + std::to_string(oxygenLevel));
  inventory.listItems();
}

void Player::takeDamage(int amount) {
  health -= amount;
  DialogueManager::displayMessage(name +
  " took " + std::to_string(amount) +
  " damage. Health is now " + std::to_string(health) + ".");

  if (health <= 0) {
    DialogueManager::displayMessage(name + " has died. Game Over.");
    game->gameOver(name + " has died.");
  }
}

void Player::pickUp(Item* item) {
  if (item == nullptr) {
    DialogueManager::displayMessage("There's nothing to pick up.");
    return;
  }

  inventory.addItem(item);
}

Inventory* Player::getInventory() {
  return &inventory;
}

void Player::dropItem(const std::string& itemName) {
  Item* item = inventory.getItem(itemName);
  if (item) {
    inventory.removeItem(item);
    DialogueManager::displayMessage("You dropped " + itemName + ".");
  } else {
    DialogueManager::displayMessage
    ("You do not have " + itemName + " to drop.");
  }
}

void Player::increaseOxygen(int amount) {
  oxygenLevel += amount;
  if (oxygenLevel > 100) {
    oxygenLevel = 100;
  }
  DialogueManager::displayMessage
  ("Your oxygen level is now " + std::to_string(oxygenLevel) + ".");
}

Game* Player::getGame() const {
  return game;
}
