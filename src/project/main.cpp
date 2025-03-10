#include <iostream>
#include <string>
#include <limits>
#include "Game.hpp"

// Function to display ASCII art and the main menu
void displayMainMenu() {
    std::cout << R"(
        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        +                                                      +
        +                _______   ______   _______            +
        +               |       | |      | |       |           +
        +               |   |   | |   |  | |   |   |           +
        +               |   |   | |   |  | |   |   |           +
        +               |___|___| |______| |_______|           +
        +                                                      +
        +              INTERGALACTIC ADVENTURE!                +
        +                                                      +
        +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    )" << "\n";
    std::cout << "Welcome to InterGalactic Adventure!\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. Creators\n";
    std::cout << "3. Instructors\n";
    std::cout << "4. Help\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

// Function to display creators
void displayCreators() {
    std::cout << R"(
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +                  CREATORS                      +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +       Suwinya Rajapakse                        +
        +       Japnoor Manku                            +
        +       Nicolas Crespo Cedeno                    +
        +       Moksh Shah                               +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
    )" << "\n";
}

// Function to display instructors
void displayInstructors() {
    std::cout << R"(
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +                  INSTRUCTORS                   +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +       Dr. Anvik                                +
        +       Nicole Wilson                           +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
    )" << "\n";
}

// Function to display help
void displayHelp() {
    std::cout << R"(
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +                     HELP                        +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
        +  1. Use commands to explore the galaxy.         +
        +  2. Look around for clues and solve puzzles.    +
        +  3. Keep your inventory updated.                +
        +  4. Follow the story to unlock new adventures.  +
        +++++++++++++++++++++++++++++++++++++++++++++++++++
    )" << "\n";
}

int main() {
    while (true) {
        displayMainMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                // Start the game
                try {
                    Game* game = new Game();
                    game->startGame();
                    delete game;
                } catch (const std::exception& e) {
                    std::cerr << "An error occurred: " << e.what() << "\n";
                    return 1;
                }
                return 0;  // Exit after the game ends
            }
            case 2:
                displayCreators();
                break;
            case 3:
                displayInstructors();
                break;
            case 4:
                displayHelp();
                break;
            case 5:
                std::cout << "Thank you for"
                 "playing InterGalactic Adventure! Goodbye.\n";
                return 0;  // Exit the program
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        // Wait for the player to press Enter before returning to the menu
        std::cout << "\nPress Enter to return to the main menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
