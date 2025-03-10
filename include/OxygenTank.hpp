/**
 * @file OxygenTank.hpp
 * @brief Represents the Oxygen Tank item.
 */

#ifndef OXYGENTANK_HPP
#define OXYGENTANK_HPP

#include "Item.hpp"

/**
 * @class OxygenTank
 * @brief An item that increases the player's oxygen level.
 */
class OxygenTank : public Item {
 public:
  /**
   * @brief Constructor for OxygenTank.
   */
  OxygenTank();

  /**
   * @brief Uses the Oxygen Tank.
   * @param player Pointer to the player using the item.
   */
  void use(Player* player) override;
};

#endif  // OXYGENTANK_HPP
