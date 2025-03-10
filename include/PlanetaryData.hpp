/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
*/

#ifndef PLANETARYDATA_H
#define PLANETARYDATA_H

#include "Item.hpp"
#include "Player.hpp"

/**
 * @class PlanetaryData
 * @brief A class representing planetary data as an item.
 * 
 * The PlanetaryData class inherits from the Item class and provides functionality
 * for interacting with this item in the context of a player.
 */
class PlanetaryData : public Item {
 public:
    /**
     * @brief Constructs a new PlanetaryData object.
     * 
     * Initializes the PlanetaryData item with default properties.
     */
    PlanetaryData();
     /**
     * @brief Uses the PlanetaryData item.
     * 
     * This function defines the behavior when the PlanetaryData is used by a player.
     * @param player A pointer to the Player object that is using the item.
     */
    void use(Player* player) override;
};

#endif
