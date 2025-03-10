/**
 * @file QuantumData.hpp
 * @brief Represents the Quantum Data item.
 */

#ifndef QUANTUMDATA_HPP
#define QUANTUMDATA_HPP

#include "Item.hpp"

/**
 * @class QuantumData
 * @brief An item that reveals key information about the universe.
 */
class QuantumData : public Item {
 public:
  /**
   * @brief Constructor for QuantumData.
   */
  QuantumData();

  /**
   * @brief Uses the Quantum Data.
   * @param player Pointer to the player using the item.
   */
  void use(Player* player) override;
};

#endif  // QUANTUMDATA_HPP
