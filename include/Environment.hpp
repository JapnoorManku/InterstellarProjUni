/**
 * @file Environment.hpp
 * @brief Abstract class representing an environment in the game.
 */

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <string>
#include <vector>
#include <map>
#include "Item.hpp"
#include "NPC.hpp"

class Player;

/**
 * @class Environment
 * @brief Abstract base class for game environments.
 */
class Environment {
 protected:
  ///< Name of the environment
  std::string name;
  ///< Current sub-location within the environment
  std::string currentSubLocation;
  ///< List of sub-locations
  std::vector<std::string> subLocations;
  ///< NPCs in each sub-location
  std::map<std::string, std::vector<NPC*>> npcs;
  ///< Items in each sub-location
  std::map<std::string, std::vector<Item*>> items;
  ///< Exits to other environments
  std::map<std::string, Environment*> exits;

 public:
  /**
   * @brief Constructor for Environment.
   * @param name The name of the environment.
   */
  explicit Environment(const std::string& name);

  /**
   * @brief Virtual destructor.
   */
  virtual ~Environment();

  /**
   * @brief Called when entering the environment.
   * @param player Pointer to the player entering.
   */
  virtual void enter(Player* player) = 0;

  /**
   * @brief Explores locations within the environment.
   * @param player Pointer to the player.
   */
  virtual void exploreLocations(Player* player) = 0;

  /**
   * @brief Gets the description of the environment.
   * @return Description of the environment.
   */
  virtual std::string getDescription() const = 0;

  /**
   * @brief Adds a sub-location to the environment.
   * @param subLocation Name of the sub-location.
   */
  void addSubLocation(const std::string& subLocation);

  /**
   * @brief Sets the current sub-location.
   * @param subLocation Name of the sub-location.
   */
  void setCurrentSubLocation(const std::string& subLocation);

  /**
   * @brief Gets the current sub-location.
   * @return Name of the current sub-location.
   */
  std::string getCurrentSubLocation() const;

  /**
   * @brief Adds an NPC to a sub-location.
   * @param subLocation Name of the sub-location.
   * @param npc Pointer to the NPC.
   */
  void addNPC(const std::string& subLocation, NPC* npc);

  /**
   * @brief Adds an item to a sub-location.
   * @param subLocation Name of the sub-location.
   * @param item Pointer to the item.
   */
  void addItem(const std::string& subLocation, Item* item);

  /**
   * @brief Gets NPCs in the current sub-location.
   * @return Vector of NPC pointers.
   */
  std::vector<NPC*> getNPCsInCurrentSubLocation() const;

  /**
   * @brief Gets items in the current sub-location.
   * @return Vector of Item pointers.
   */
  std::vector<Item*> getItemsInCurrentSubLocation() const;

  /**
   * @brief Sets an exit to another environment.
   * @param direction The direction of the exit.
   * @param environment Pointer to the environment.
   */
  void setExit(const std::string& direction, Environment* environment);

  /**
   * @brief Gets the exits from this environment.
   * @return A const reference to a map of exits.
   */
  const std::map<std::string, Environment*>& getExits() const;

  /**
   * @brief Gets the name of the environment.
   * @return Name of the environment.
   */
  const std::string getName() const;
};

#endif  // ENVIRONMENT_HPP
