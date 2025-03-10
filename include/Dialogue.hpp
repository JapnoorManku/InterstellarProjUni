/**
 * @file Dialogue.hpp
 * @brief Handles dialogue interactions with NPCs.
 */

#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <string>
#include <vector>

/**
 * @class Dialogue
 * @brief Manages dialogues with NPCs.
 */
class Dialogue {
 private:
  std::string npcName;              ///< Name of the NPC
  std::vector<std::string> options; ///< Dialogue options
  int correctOption;                ///< Index of the correct option

 public:
  /**
   * @brief Constructor for Dialogue.
   * @param npcName Name of the NPC.
   * @param options List of dialogue options.
   * @param correctOption Index of the correct option.
   */
  Dialogue(const std::string& npcName,
           const std::vector<std::string>& options,
           int correctOption);

  /**
   * @brief Destructor for Dialogue.
   */
  ~Dialogue();

  /**
   * @brief Engages the dialogue with the player.
   * @return True if the correct option is chosen, false otherwise.
   */
  bool engage();
};

#endif  // DIALOGUE_HPP
