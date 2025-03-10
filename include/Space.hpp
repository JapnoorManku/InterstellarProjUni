#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Environment.hpp"
#include "Player.hpp"

/**
 * @class Space
 * @brief Represents the space environment in the game.
 *
 * This class allows the player to enter the space environment, navigate through the wormhole by completing a task,
 * and move to the next environment once the task is successfully completed.
 */
class Space : public Environment {
 public:
    /**
     * @brief Constructor to initialize the space environment.
     *
     * Sets up the sublocations within space, such as "Near Wormhole" and "Out of Wormhole".
     */
    Space();

    /**
     * @brief Destructor for the Space class.
     *
     * Cleans up any resources or objects associated with this environment, though not strictly needed here.
     */
    virtual ~Space();

    /**
     * @brief Method to enter the space environment.
     *
     * This method is called when the player enters the space environment. It displays an introductory message and
     * begins the exploration task.
     *
     * @param player A pointer to the player who is entering the space environment.
     */
    void enter(Player* player) override;

    /**
     * @brief Get a description of the space environment.
     *
     * This method returns a description of the space environment, providing context for the player when they are in space.
     *
     * @return A string containing the description of space.
     */
    std::string getDescription() const override;

    /**
     * @brief Method to explore locations within the space environment.
     *
     * Handles the navigation task for the wormhole, asking the player to input the correct sequence of commands.
     * Once the task is completed successfully, the player is moved to the next location.
     *
     * @param player A pointer to the player exploring the environment.
     */
    void exploreLocations(Player* player) override;

 private:
};

#endif // SPACE_HPP
