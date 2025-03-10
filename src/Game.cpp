/**
 * @file Game.cpp
 * @brief Implements the Game class methods.
 */

#include <iostream>
#include <limits>
#include <string>
#include "Game.hpp"
#include "CoopersHouse.hpp"
#include "CommandParser.hpp"
#include "DialogueManager.hpp"

Game::Game() : gameRunning(true) {
  player = new Player("Cooper", this);  // Pass 'this' to the player
  parser = new CommandParser(this);     // Initialize command parser
}

Game::~Game() {
  delete player;
  delete parser;
}

void Game::initializeGame() {
  CoopersHouse* coopersHouse = new CoopersHouse();
  player->move(coopersHouse);  // Start the player in Cooper's House
}

void Game::startGame() {
  DialogueManager::displayMessage("Welcome to InterGalactic Adventure!");
  initializeGame();

  while (gameRunning) {
    update();
  }
}

void Game::update() {
  displayToolbar();
  std::string input;
  std::getline(std::cin, input);

  // Trim whitespace from input (optional)
  input.erase(input.find_last_not_of(" \n\r\t") + 1);

  if (input.empty()) {
    return;
  }

  parser->parseCommand(input);

  // Wait for the player to press Enter before clearing the console
  std::cout << "\nPress Enter to continue...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Clear the console before the next update
  clearConsole();
}

void Game::gameOver(const std::string& reason) {
  DialogueManager::displayMessage("Game Over: " + reason);
  gameRunning = false;
}

Player* Game::getPlayer() {
  return player;
}

void Game::displayHelp() const {
  DialogueManager::displayMessage
  ("Available commands:\n- look\n- move\n- inventory\n- help\n- exit");
}

void Game::displayToolbar() {
  std::cout << "\nCurrent location: " << player->getCurrentLocation
  ()->getName()
            << " - " << player->getCurrentLocation
            ()->getCurrentSubLocation() << "\n";
  DialogueManager::displayMessage
  ("1. Look | 2. Move | 3. Inventory | 4. Help | 5. Exit");
  std::cout << "Choose an action: ";
}

void Game::clearConsole() {
  // ANSI escape code to clear screen
  std::cout << "\033[2J\033[1;1H";
}
