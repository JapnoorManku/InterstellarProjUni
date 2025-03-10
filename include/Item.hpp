/**
 * @file Item.hpp
 * @brief Abstract base class for items in the game.
 */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Player;  // Forward declaration

/**
 * @class Item
 * @brief Abstract class representing an item.
 */
class Item {
 protected:
  std::string name;  ///< Name of the item

 public:
  /**
   * @brief Constructor for Item.
   * @param name The name of the item.
   */
  Item(const std::string& name);

  /**
   * @brief Virtual destructor.
   */
  virtual ~Item();

  /**
   * @brief Pure virtual method to use the item.
   * @param player Pointer to the player using the item.
   */
  virtual void use(Player* player) = 0;

  /**
   * @brief Gets the name of the item.
   * @return Name of the item.
   */
  std::string getName() const;
};

#endif  // ITEM_HPP
