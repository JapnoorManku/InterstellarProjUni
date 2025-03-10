/**
 * @file Inventory.hpp
 * @brief Manages the player's inventory.
 */

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include "Item.hpp"

/**
 * @class Inventory
 * @brief Represents the player's inventory of items.
 */
class Inventory {
 private:
  std::vector<Item*> items;  ///< List of items in the inventory

 public:
  /**
   * @brief Constructor for Inventory.
   */
  Inventory();

  /**
   * @brief Destructor for Inventory.
   */
  ~Inventory();

  /**
   * @brief Adds an item to the inventory.
   * @param item Pointer to the item to add.
   */
  void addItem(Item* item);

  /**
   * @brief Removes an item from the inventory.
   * @param item Pointer to the item to remove.
   */
  void removeItem(Item* item);

  /**
   * @brief Gets an item by name.
   * @param name The name of the item.
   * @return Pointer to the item if found, nullptr otherwise.
   */
  Item* getItem(const std::string& name) const;

  /**
   * @brief Lists all items in the inventory.
   */
  void listItems() const;
};

#endif  // INVENTORY_HPP
