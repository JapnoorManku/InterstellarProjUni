/**
 * @file Inventory.cpp
 * @brief Implements the Inventory class methods.
 */

#include <iostream>
#include <algorithm>
#include "Inventory.hpp"
#include "DialogueManager.hpp"

Inventory::Inventory() {}

Inventory::~Inventory() {
  for (Item* item : items) {
    delete item;  // Free allocated memory for each item
  }
}

void Inventory::addItem(Item* item) {
  if (item) {
    items.push_back(item);
    DialogueManager::displayMessage(item->getName() +
    " has been added to your inventory.");
  } else {
    DialogueManager::displayMessage
    ("Invalid item. Cannot add to inventory.");
  }
}

void Inventory::removeItem(Item* item) {
  if (!item) {
    DialogueManager::displayMessage
    ("Invalid item. Cannot remove from inventory.");
    return;
  }

  auto it = std::find(items.begin(), items.end(), item);
  if (it != items.end()) {
    items.erase(it);
    DialogueManager::displayMessage(item->getName() +
    " has been removed from your inventory.");
  } else {
    DialogueManager::displayMessage("Item not found in inventory.");
  }
}

Item* Inventory::getItem(const std::string& name) const {
  auto it = std::find_if(items.begin(),
  items.end(), [&name](Item* item) {
    return item->getName() == name;
  });

  if (it != items.end()) {
    return *it;
  } else {
    return nullptr;
  }
}

void Inventory::listItems() const {
  if (items.empty()) {
    DialogueManager::displayMessage("Your inventory is empty.");
    return;
  }

  DialogueManager::displayMessage("Your inventory contains:");
  for (const Item* item : items) {
    std::cout << "- " << item->getName() << "\n";
  }
}
