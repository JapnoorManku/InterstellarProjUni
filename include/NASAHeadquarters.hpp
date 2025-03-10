/**
 * @file NASAHeadquarters.hpp
 * @brief Represents the NASA Headquarters environment.
 */

#ifndef NASAHEADQUARTERS_HPP
#define NASAHEADQUARTERS_HPP

#include <string>
#include "Environment.hpp"

/**
 * @class NASAHeadquarters
 * @brief Represents NASA Headquarters as an environment.
 */
class NASAHeadquarters : public Environment {
 public:
  /**
   * @brief Constructor for NASAHeadquarters.
   */
  NASAHeadquarters();

  /**
   * @brief Called when the player enters NASA Headquarters.
   * @param player Pointer to the player.
   */
  void enter(Player* player) override;

  /**
   * @brief Gets the description of NASA Headquarters.
   * @return Description string.
   */
  std::string getDescription() const override;

  /**
   * @brief Explores locations within NASA Headquarters.
   * @param player Pointer to the player.
   */
  void exploreLocations(Player* player) override;

// After completing Task 2, we call a method to start the fuel quest
  void startFuelQuest();

 private:
  int fuelCount;
  bool gotJanitorFuel;
  bool gotColdRoomFuel;
  bool fuelQuestActive;
};

#endif  // NASAHEADQUARTERS_HPP
