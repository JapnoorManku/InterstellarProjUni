/**
 * @file Earth.hpp
 * @brief Represents the Earth environment.
 */

#ifndef EARTH_HPP
#define EARTH_HPP

#include <string>
#include "Environment.hpp"
#include "Player.hpp"

/**
 * @class Earth
 * @brief Represents Earth as an environment.
 */
class Earth : public Environment {
 public:
  /**
   * @brief Constructor for Earth.
   */
  Earth();

  /**
   * @brief Called when the player enters Earth.
   * @param player Pointer to the player.
   */
  void enter(Player* player) override;

  /**
   * @brief Gets the description of Earth.
   * @return Description string.
   */
  std::string getDescription() const override;

  /**
   * @brief Explores locations on Earth.
   * @param player Pointer to the player.
   */
  void exploreLocations(Player* player) override;
};

#endif  // EARTH_HPP
