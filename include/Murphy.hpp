/**
 * @file Murphy.hpp
 * @brief Represents the NPC Murphy.
 */

#ifndef MURPHY_HPP
#define MURPHY_HPP

#include "NPC.hpp"

/**
 * @class Murphy
 * @brief Represents Murphy NPC.
 */
class Murphy : public NPC {
 public:
  /**
   * @brief Constructor for Murphy.
   */
  Murphy();

  /**
   * @brief Interaction with the player.
   * @param player Pointer to the player.
   */
  void interact(Player* player) override;
};

#endif  // MURPHY_HPP
