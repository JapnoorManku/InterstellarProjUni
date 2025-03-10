/**
 * @file Item.cpp
 * @brief Implements the Item class methods.
 */

#include "Item.hpp"

Item::Item(const std::string& name) : name(name) {}

Item::~Item() {}

std::string Item::getName() const {
  return name;
}
