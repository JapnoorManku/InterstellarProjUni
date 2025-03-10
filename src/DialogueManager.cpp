/**
 * @file DialogueManager.cpp
 * @brief Implements the DialogueManager class methods.
 */

#include <iostream>
#include <cctype>
#include <limits>
#include "DialogueManager.hpp"

void DialogueManager::displayMessage(const std::string& message) {
  std::cout << message << "\n";
}

char DialogueManager::getYesNo(const std::string& prompt) {
  char choice;
  std::cout << prompt << " (Y/N): ";
  while (true) {
    std::cin >> choice;
    choice = toupper(choice);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 'Y' || choice == 'N') {
      return choice;
    }
    std::cout << "Invalid input. Please enter Y or N: ";
  }
}

int DialogueManager::getChoice(const std::string& prompt, int min, int max) {
  int choice;
  std::cout << prompt;
  while (!(std::cin >> choice) || choice < min || choice > max) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid choice. " << prompt;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return choice;
}

std::string DialogueManager::getInput(const std::string& prompt) {
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input);
  return input;
}
