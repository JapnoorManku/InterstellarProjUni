/**
 * @file Character.cpp
 * @author
 *   Japnoor Manku <japnoor.manku@uleth.ca>,
 *   Nicolas Cedeno <n.crespo@uleth.ca>
 * @date 2024-11-23
 * @brief Implements the Character class methods.
 */

#include "Character.hpp"

Character::Character(const std::string& name) : name(name) {}

std::string Character::getName() const {
  return name;
}
