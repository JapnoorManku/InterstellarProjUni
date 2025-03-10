/**
 * @file Game.hpp
 * @brief Manages the overall game logic.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "Environment.hpp"
#include "Player.hpp"
#include "CommandParser.hpp"

/**
 * @class Game
 * @brief Main game class that initializes and runs the game.
 */
class Game {
 private:
  Player* player;           ///< Pointer to the player character
  CommandParser* parser;    ///< Command parser
  bool gameRunning;         ///< Flag to control the game loop

 public:
  /**
   * @brief Constructor for Game.
   */
  Game();

  /**
   * @brief Destructor for Game.
   */
  ~Game();

  /**
   * @brief Starts the game.
   */
  void startGame();

  /**
   * @brief Initializes game environments and characters.
   */
  void initializeGame();

  /**
   * @brief Updates the game state.
   */
  void update();

  /**
   * @brief Ends the game with a reason.
   * @param reason The reason for game over.
   */
  void gameOver(const std::string& reason);

  /**
   * @brief Gets the player object.
   * @return Pointer to the player.
   */
  Player* getPlayer();

  /**
   * @brief Displays help information.
   */
  void displayHelp() const;

  /**
   * @brief Displays the toolbar interface.
   */
  void displayToolbar();

  /**
   * @brief Clears the console screen.
   */
  void clearConsole();
};

#endif  // GAME_HPP
