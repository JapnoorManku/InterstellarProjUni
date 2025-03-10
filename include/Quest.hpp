/**
 * @file Quest.hpp
 * @brief Represents a quest in the game.
 */

#ifndef QUEST_HPP
#define QUEST_HPP

#include <string>
#include "Player.hpp"
#include "Item.hpp"
#include "Puzzle.hpp"

/**
 * @class Quest
 * @brief Manages quests for the player.
 */
class Quest {
 private:
  std::string description;  ///< Quest description
  bool isCompleted;         ///< Completion status
  Puzzle* puzzle;           ///< Associated puzzle (optional)

 public:
  /**
   * @brief Constructor for Quest.
   * @param description The description of the quest.
   */
  Quest(const std::string& description, Puzzle* puzzle);

  /**
   * @brief Destructor for Quest.
   */
  ~Quest();

  /**
   * @brief Attempts to complete the quest.
   * @param player Pointer to the player.
   * @return True if the quest is completed, false otherwise.
   */
  bool attempt(Player* player);

  /**
   * @brief Displays quest information.
   */
  void displayQuestInfo() const;
};

#endif  // QUEST_HPP
