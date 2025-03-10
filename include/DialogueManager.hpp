/**
 * @file DialogueManager.hpp
 * @brief Manages dialogues and user prompts.
 */

#ifndef DIALOGUEMANAGER_HPP
#define DIALOGUEMANAGER_HPP
#include <string>

/**
 * @class DialogueManager
 * @brief Handles display of messages and user input.
 */
class DialogueManager {
 public:
  /**
   * @brief Displays a message to the player.
   * @param message The message to display.
   */
  static void displayMessage(const std::string& message);

  /**
   * @brief Gets a yes/no response from the player.
   * @param prompt The prompt message.
   * @return 'Y' or 'N' based on player input.
   */
  static char getYesNo(const std::string& prompt);

  /**
   * @brief Gets a choice from the player within a range.
   * @param prompt The prompt message.
   * @param min The minimum valid choice.
   * @param max The maximum valid choice.
   * @return The player's choice.
   */
  static int getChoice(const std::string& prompt, int min, int max);
  static std::string getInput(const std::string& prompt);
};

#endif  // DIALOGUEMANAGER_HPP
