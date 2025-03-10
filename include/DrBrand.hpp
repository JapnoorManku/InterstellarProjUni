/**
 * @file DrBrand.hpp
 * @brief Represents the NPC Dr. Brand.
 */

#ifndef DRBRAND_HPP
#define DRBRAND_HPP

#include "NPC.hpp"
#include "Dialogue.hpp"

/**
 * @class DrBrand
 * @brief Represents Dr. Brand NPC.
 */
class DrBrand : public NPC {
 public:
  /**
   * @brief Constructor for DrBrand.
   */
  DrBrand();

  /**
   * @brief Interaction with the player.
   * @param player Pointer to the player.
   */
  void interact(Player* player) override;
};

#endif  // DRBRAND_HPP
