/**
 * @file CoordinateMap.hpp
 * @brief Represents the Coordinate Map item.
 */

#ifndef COORDINATEMAP_HPP
#define COORDINATEMAP_HPP

#include "Item.hpp"

/**
 * @class CoordinateMap
 * @brief An item that reveals NASA's location.
 */
class CoordinateMap : public Item {
 public:
  /**
   * @brief Constructor for CoordinateMap.
   */
  CoordinateMap();

  /**
   * @brief Uses the Coordinate Map.
   * @param player Pointer to the player using the item.
   */
  void use(Player* player) override;
};

#endif  // COORDINATEMAP_HPP
