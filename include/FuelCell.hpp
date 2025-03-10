/**
 * @file FuelCell.hpp
 * @brief Represents the Fuel Cell item.
 */

#ifndef FUELCELL_HPP
#define FUELCELL_HPP

#include "Item.hpp"

/**
 * @class FuelCell
 * @brief An item that refuels the spacecraft.
 */
class FuelCell : public Item {
 public:
  /**
   * @brief Constructor for FuelCell.
   */
  FuelCell();

  /**
   * @brief Uses the Fuel Cell.
   * @param player Pointer to the player using the item.
   */
  void use(Player* player) override;
};

#endif  // FUELCELL_HPP
