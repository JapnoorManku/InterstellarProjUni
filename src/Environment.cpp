/**
 * @file Environment.cpp
 * @brief Implements the Environment class methods.
 */

#include "Environment.hpp"

Environment::Environment(const std::string& name)
    : name(name), currentSubLocation("") {}

Environment::~Environment() {
  for (auto& itemList : items) {
    for (auto item : itemList.second) {
      delete item;
    }
  }
  for (auto& npcList : npcs) {
    for (auto npc : npcList.second) {
      delete npc;
    }
  }
  for (auto exit : exits) {
    delete exit.second;
  }
}

void Environment::addSubLocation(const std::string& subLocation) {
  subLocations.push_back(subLocation);
}

void Environment::setCurrentSubLocation(const std::string& subLocation) {
  currentSubLocation = subLocation;
}

std::string Environment::getCurrentSubLocation() const {
  return currentSubLocation;
}

void Environment::addNPC(const std::string& subLocation, NPC* npc) {
  npcs[subLocation].push_back(npc);
}

void Environment::addItem(const std::string& subLocation, Item* item) {
  items[subLocation].push_back(item);
}

std::vector<NPC*> Environment::getNPCsInCurrentSubLocation() const {
  auto it = npcs.find(currentSubLocation);
  if (it != npcs.end()) {
    return it->second;
  }
  return {};
}

std::vector<Item*> Environment::getItemsInCurrentSubLocation() const {
  auto it = items.find(currentSubLocation);
  if (it != items.end()) {
    return it->second;
  }
  return {};
}

void Environment::setExit
(const std::string& direction, Environment* environment) {
  exits[direction] = environment;
}

const std::map<std::string, Environment*>& Environment::getExits() const {
  return exits;
}

const std::string Environment::getName() const {
  return name;
}
