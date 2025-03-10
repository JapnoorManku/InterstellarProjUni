/**
 * @file SpaceSuit.hpp
 * @brief Represents the Space Suit item.
 */

#ifndef SPACESUIT_HPP
#define SPACESUIT_HPP

#include "Item.hpp"

/**
 * @class SpaceSuit
 * @brief An item that protects the player from space hazards.
 */
class SpaceSuit : public Item {
 public:
  /**
   * @brief Constructor for SpaceSuit.
   */
  SpaceSuit();

  /**
   * @brief Uses the Space Suit.
   * @param player Pointer to the player using the item.
   */
  void use(Player* player) override;
};

#endif  // SPACESUIT_HPP
