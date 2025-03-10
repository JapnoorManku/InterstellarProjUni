/**
 * @file NPC.hpp
 * @brief Abstract base class for non-player characters (NPCs).
 */

#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include "Character.hpp"

/**
 * @class NPC
 * @brief Abstract class representing an NPC.
 */
class NPC : public Character {
 public:
  /**
   * @brief Constructor for NPC.
   * @param name The name of the NPC.
   */
  NPC(const std::string& name);

  /**
   * @brief Virtual destructor.
   */
  ~NPC() override;
};

#endif  // NPC_HPP
