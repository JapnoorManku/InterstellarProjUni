/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
 */

#ifndef WATERPLANET_H
#define WATERPLANET_H

#include <string>
#include "Environment.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

/**
 * @class WaterPlanet
 * @brief Represents a water-themed planet in the game environment.
 * 
 * This class inherits from the Environment class and implements the functionality
 * for a water-based planet. Players can explore, face challenges like tidal waves,
 * and interact with the environment.
 */
class WaterPlanet : public Environment {
 public:
    /**
     * @brief Default constructor for the WaterPlanet class.
     * 
     * Initializes the WaterPlanet with default properties.
     */
    WaterPlanet();

    /**
     * @brief Allows a player to enter the WaterPlanet environment.
     * 
     * This function is triggered when a player enters the WaterPlanet.
     * It sets up necessary conditions for the player and updates the game state.
     * 
     * @param player Pointer to the Player entering the WaterPlanet.
     */
    void enter(Player* player) override;

    /**
     * @brief Gets the description of the WaterPlanet.
     * 
     * Provides a textual description of the WaterPlanet environment.
     * 
     * @return A string containing the description of the WaterPlanet.
     */
    std::string getDescription() const override;

    /**
     * @brief Allows the player to explore various locations on the WaterPlanet.
     * 
     * This function provides interaction points for the player, enabling
     * exploration and discovery of the planet's features and secrets.
     * 
     * @param player Pointer to the Player exploring the WaterPlanet.
     */
    void exploreLocations(Player* player) override;

    /**
     * @brief Triggers a tidal wave event on the WaterPlanet.
     * 
     * This function activates a tidal wave, which could pose a challenge
     * or change the environment for the player.
     */
    void triggerTidalWave();

 private:
    bool tidalWaveIncoming; // Flag indicating whether a tidal wave is incoming.
    int timeLeft;           // Time left before a significant event occurs.
};

#endif
