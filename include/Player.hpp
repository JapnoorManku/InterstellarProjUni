/**
 * @file Player.hpp
 * @brief Represents the player character.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <utility>
#include <string>
#include <vector>
#include "Environment.hpp"
#include "Inventory.hpp"
#include "Character.hpp"

class Game;  // Forward declaration

/**
 * @class Player
 * @brief Represents the player-controlled character.
 */
class Player : public Character {
 private:
  Environment* currentLocation;  ///< Current environment
  Inventory inventory;           ///< Player's inventory
  int health;                    ///< Player's health
  int oxygenLevel;               ///< Player's oxygen level
  Game* game;                    ///< Pointer to the game object
  //std::vector<Item*> inventory; //Storing items in a vector

 public:
  /**
   * @brief Constructor for Player.
   * @param name The name of the player.
   * @param game Pointer to the game object.
   */
  Player(const std::string& name, Game* game);

  /**
   * @brief Destructor for Player.
   */
  ~Player();

  // /**
  //  * @brief Adds an item to the player's invetory.
  //  * @param item A pointer to Item object to be added to the inventory.
  //  */
  // void addItem(Item* item);

  /**
   * @brief Moves within the current location or to a new location.
   * @param newLocation Pointer to the new environment (optional).
   */
  void move(Environment* newLocation = nullptr);

  /**
   * @brief Uses an item from the inventory.
   * @param itemName The name of the item to use.
   */
  void useItem(const std::string& itemName);

  /**
   * @brief Talks to an NPC.
   * @param npcName The name of the NPC to talk to.
   */
  void talkTo(const std::string& npcName);

  /**
   * @brief Checks the player's status.
   */
  void checkStatus() const;

  /**
   * @brief Checks if the player has a specific item.
   * @param itemName The name of the item.
   * @return True if the player has the item, false otherwise.
   */
  bool hasItem(const std::string& itemName) const;

  /**
   * @brief Takes damage and updates health.
   * @param amount The amount of damage.
   */
  void takeDamage(int amount);

  /**
   * @brief Picks up an item.
   * @param item Pointer to the item to pick up.
   */
  void pickUp(Item* item);

  /**
   * @brief Gets the current location.
   * @return Pointer to the current environment.
   */
  Environment* getCurrentLocation() const;

  /**
   * @brief Gets the inventory.
   * @return Pointer to the inventory.
   */
  Inventory* getInventory();

  /**
   * @brief Drops an item from the inventory.
   * @param itemName The name of the item to drop.
   */
  void dropItem(const std::string& itemName);

  /**
   * @brief Interaction method (not used for Player).
   * @param player Pointer to the other player (unused).
   */
  void interact(Player* player) override;

  /**
   * @brief Increases the player's oxygen level.
   * @param amount Amount to increase.
   */
  void increaseOxygen(int amount);

  /**
   * @brief Gets the game object.
   * @return Pointer to the game.
   */
  Game* getGame() const;
};

#endif  // PLAYER_HPP
