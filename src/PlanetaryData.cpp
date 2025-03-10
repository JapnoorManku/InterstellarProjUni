/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
 */

#include <iostream>
#include "PlanetaryData.hpp"

PlanetaryData::PlanetaryData() : Item("Planetary Data") {}

void PlanetaryData::use(Player* player) {
    std::cout << "Using Planetary Data...\n";
}
