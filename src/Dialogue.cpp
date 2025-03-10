/**
 * @file Dialogue.cpp
 * @brief Implements the Dialogue class methods.
 */

#include <iostream>
#include "Dialogue.hpp"
#include "DialogueManager.hpp"

Dialogue::Dialogue(const std::string& npcName,
const std::vector<std::string>& options, int correctOption)
    : npcName(npcName), options(options), correctOption(correctOption) {}

Dialogue::~Dialogue() {}

bool Dialogue::engage() {
  DialogueManager::displayMessage
  (npcName + ": \"What do you have to say for yourself?\"");
  for (size_t i = 0; i < options.size(); ++i) {
    std::cout << i + 1 << ". " << options[i] << std::endl;
  }
  int choice = DialogueManager::getChoice
  ("Choose an option: ", 1, options.size());

  if (choice == correctOption) {
    DialogueManager::displayMessage
    (npcName + ": \"Impressive. You've proven yourself worthy.\"");
    return true;
  } else {
    DialogueManager::displayMessage
    (npcName + ": \"I'm sorry, but I can't trust you with this mission.\"");
    return false;
  }
}
