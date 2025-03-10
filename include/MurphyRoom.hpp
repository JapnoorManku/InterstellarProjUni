/**
 * @file MurphyRoom.hpp
 * @brief Represents Murphy's Room environment.
 */

#ifndef MURPHYROOM_HPP
#define MURPHYROOM_HPP

#include <string>
#include "Environment.hpp"

/**
 * @class MurphyRoom
 * @brief Represents Murphy's Room as an environment.
 */
class MurphyRoom : public Environment {
 public:
  /**
   * @brief Constructor for MurphyRoom.
   * @param coopersHouse Pointer to Cooper's House environment.
   */
  MurphyRoom(Environment* coopersHouse);

  /**
   * @brief Destructor for MurphyRoom.
   */
  ~MurphyRoom();

  /**
   * @brief Called when the player enters Murphy's Room.
   * @param player Pointer to the player.
   */
  void enter(Player* player) override;

  /**
   * @brief Gets the description of Murphy's Room.
   * @return Description string.
   */
  std::string getDescription() const override;

  /**
   * @brief Explores locations within Murphy's Room.
   * @param player Pointer to the player.
   */
  void exploreLocations(Player* player) override;
};

#endif  // MURPHYROOM_HPP
