/**
 * @file CoopersHouse.hpp
 * @brief Represents Cooper's House environment.
 */

#ifndef COOPERSHOUSE_HPP
#define COOPERSHOUSE_HPP

#include <string>
#include "Environment.hpp"

/**
 * @class CoopersHouse
 * @brief Represents Cooper's House environment.
 */
class CoopersHouse : public Environment {
 public:
  /**
   * @brief Constructor for CoopersHouse.
   */
  CoopersHouse();

  /**
   * @brief Called when the player enters Cooper's House.
   * @param player Pointer to the player.
   */
  void enter(Player* player) override;

  /**
   * @brief Gets the description of Cooper's House.
   * @return Description string.
   */
  std::string getDescription() const override;

  /**
   * @brief Explores locations within Cooper's House.
   * @param player Pointer to the player.
   */
  void exploreLocations(Player* player) override;
};

#endif  // COOPERSHOUSE_HPP
