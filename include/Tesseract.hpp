/**
 * @file Tesseract.hpp
 * @brief Declaration of the Tesseract class.
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.cs>
 * This file defines the Tesseract class, which inherits from the Environment class.
 * The Tesseract represents a unique area with puzzles, exploration mechanics, and spatial shifts.
 */

#ifndef TESSERACT_H
#define TESSERACT_H

#include <string>
#include "Environment.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

/**
 * @class Tesseract
 * @brief A class representing a tesseract environment.
 * 
 * The Tesseract class provides functionalities for players to enter, explore, solve puzzles,
 * and experience spatial shifts within this unique environment.
 */
class Tesseract : public Environment {
 private:
    bool puzzleSolved;
    /**< Indicates whether the puzzle in the Tesseract has been solved. */
    int timeShift;
    /**< Represents the current time shift state of the Tesseract. */

 public:
    /**
     * @brief Constructs a new Tesseract object.
     * 
     * Initializes the Tesseract environment with default properties.
     */
    Tesseract();

    /**
     * @brief Allows a player to enter the Tesseract.
     * 
     * This function defines the behavior when a player enters the Tesseract environment.
     * @param player A pointer to the Player object entering the Tesseract.
     */
    virtual void enter(Player* player);

    /**
     * @brief Retrieves the description of the Tesseract.
     * 
     * This function returns a description of the Tesseract environment.
     * @return A string containing the description of the Tesseract.
     */
    virtual std::string getDescription() const;

    /**
     * @brief Allows the player to explore various locations within the Tesseract.
     * 
     * This function provides mechanics for players to explore different areas in the Tesseract.
     * @param player A pointer to the Player object exploring the Tesseract.
     */
    void exploreLocations(Player* player);

    /**
     * @brief Solves the puzzle within the Tesseract.
     * 
     * This function provides logic for solving the Tesseract's puzzle.
     * @param player A pointer to the Player object attempting to solve the puzzle.
     */
    void solvePuzzle(Player* player);

    /**
     * @brief Triggers a spatial shift in the Tesseract.
     * 
     * This function alters the state of the Tesseract, simulating a spatial or temporal shift.
     */
    void triggerSpatialShift();
};

#endif // TESSERACT_HPP
