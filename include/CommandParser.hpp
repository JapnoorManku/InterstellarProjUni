/**
 * @file CommandParser.hpp
 * @brief Parses player commands.
 */

#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <string>

class Game;

/**
 * @class CommandParser
 * @brief Handles parsing of player commands.
 */
class CommandParser {
 private:
  Game* game;  ///< Pointer to the game object

 public:
  /**
   * @brief Constructor for CommandParser.
   * @param game Pointer to the game object.
   */
  CommandParser(Game* game);

  /**
   * @brief Destructor for CommandParser.
   */
  ~CommandParser();

  /**
   * @brief Parses a command input by the player.
   * @param input The player's input.
   */
  void parseCommand(const std::string& input);
};

#endif  // COMMANDPARSER_HPP
