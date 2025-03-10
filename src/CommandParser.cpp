/**
 * @file CommandParser.cpp
 * @brief Implements the CommandParser class methods.
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <limits>
#include "CommandParser.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "DialogueManager.hpp"

CommandParser::CommandParser(Game* game) : game(game) {}

CommandParser::~CommandParser() {}

void CommandParser::parseCommand(const std::string& input) {
  // Trim leading and trailing whitespace
  std::string cmd = input;
  cmd.erase(0, cmd.find_first_not_of(" \n\r\t"));
  cmd.erase(cmd.find_last_not_of(" \n\r\t") + 1);

  // Convert input to lowercase for case-insensitive comparison
  std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

  int commandNumber = 0;
  bool isNumber = false;

  try {
    commandNumber = std::stoi(cmd);
    isNumber = true;
  } catch (const std::invalid_argument&) {
    // Input is not a number
  }

  if (isNumber && commandNumber == 1 || cmd == "look") {
    // Handle "look" command
    DialogueManager::displayMessage(game->getPlayer()
    ->getCurrentLocation()->getDescription());
  } else if (isNumber && commandNumber == 2 || cmd == "move") {
    // Handle "move" command
    game->getPlayer()->move();
  } else if (isNumber && commandNumber == 3 || cmd == "inventory") {
    // Handle "inventory" command
    game->getPlayer()->checkStatus();
  } else if (isNumber && commandNumber == 4 || cmd == "help") {
    // Handle "help" command
    game->displayHelp();
  } else if (isNumber && commandNumber == 5 || cmd == "exit") {
    // Handle "exit" command
    game->gameOver("Thank you for playing!");
  } else {
    DialogueManager::displayMessage("Unknown command.");
  }
}

