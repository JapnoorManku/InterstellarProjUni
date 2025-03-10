/**
 * @file Character.hpp
 * @brief Abstract base class for characters in the game.
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Player;  // Forward declaration

/**
 * @class Character
 * @brief Abstract base class representing a character.
 */
class Character {
 protected:
  std::string name;  ///< Name of the character

 public:
  /**
   * @brief Constructor for Character.
   * @param name The name of the character.
   */
  Character(const std::string& name);

  /**
   * @brief Virtual destructor.
   */
  virtual ~Character() = default;

  /**
   * @brief Gets the name of the character.
   * @return Name of the character.
   */
  std::string getName() const;

  /**
   * @brief Pure virtual interaction method.
   * @param player Pointer to the player.
   */
  virtual void interact(Player* player) = 0;
};

#endif  // CHARACTER_HPP
