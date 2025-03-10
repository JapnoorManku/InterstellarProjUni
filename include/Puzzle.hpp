/**
 * @author Japnoor Manku <japnoor.manku@uleth.ca>
 * @date 2024-12-04
*/
#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <string>
#include <vector>
#include <utility>

class DialogueManager;

/**
 * @class Puzzle
 * @brief A class representing a puzzle.
 * 
 * The Puzzle class encapsulates the properties and methods required to define
 * and solve different types of puzzles. These puzzles can involve numeric,
 * word-based, or sequence challenges.
 */
class Puzzle {
 private:
    std::string description;                // Puzzle description
    std::vector<std::string> binaryLines;   // Binary strings for the puzzle
    std::pair<int, int> correctCoordinates; // Correct coordinates
    std::string correctWord;
    bool isSolved;                          // Whether the puzzle is solved

 public:
   /**
     * @brief Constructs a Puzzle object.
     * 
     * Initializes the puzzle with a description, binary lines, correct coordinates, and an optional correct word.
     * 
     * @param description A brief description of the puzzle.
     * @param binaryLines A vector of binary strings relevant to the puzzle.
     * @param correctCoordinates The correct coordinates for solving the puzzle.
     * @param correctWord The correct word for solving the puzzle (optional).
     */
    Puzzle(const std::string& description,
         const std::vector<std::string>& binaryLines,
         const std::pair<int, int>& correctCoordinates,
         const std::string& correctWord = "");

    /**
     * @brief Displays the puzzle to the user.
     * 
     * This function outputs the puzzle description and relevant details to help the user solve it.
     */
    void display() const;

    /**
     * @brief Attempts to solve a numeric puzzle.
     * 
     * This function checks if the user's solution matches the puzzle's numeric requirements.
     * 
     * @return True if the puzzle is solved, false otherwise.
     */
    bool attempt();

    /**
     * @brief Attempts to solve a word-based puzzle.
     * 
     * This function checks if the user's word matches the correct word for the puzzle.
     * 
     * @return True if the puzzle is solved, false otherwise.
     */
    bool attemptWord();

    /**
     * @brief Solves a navigational sequence puzzle.
     * 
     * This function validates if the provided sequence matches the correct navigational sequence.
     * 
     * @param correctSequence A vector of strings representing the correct sequence.
     * @return True if the sequence is correct, false otherwise.
     */
    bool solveNavigationalSequence
    (const std::vector<std::string>& correctSequence);

    /**
     * @brief Solves a timed sequence puzzle.
     * 
     * This function determines if the puzzle can be solved within a time limit and with the required actions.
     * 
     * @param timeLimit The time limit for solving the puzzle.
     * @param requiredActions The number of actions required to solve the puzzle.
     * @return True if the puzzle is solved within the constraints, false otherwise.
     */
    bool solveTimedSequence(int timeLimit, int requiredActions);

    /**
     * @brief Solves a Morse code puzzle.
     * 
     * This function validates the provided Morse code sequence against the correct sequence.
     * 
     * @param correctSequence A vector of pairs representing the Morse code and its meaning.
     * @return True if the sequence matches, false otherwise.
     */
    bool solveMorseCode
    (const std::vector<std::pair<std::string, std::string>>& correctSequence);
};

#endif // PUZZLE_HPP
