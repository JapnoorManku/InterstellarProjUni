/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
*/

#include <iostream>
#include "TesseractKey.hpp"

TesseractKey::TesseractKey() : Item("Planetary Data") {}

void TesseractKey::use(Player* player) {
    std::cout << "Using Planetary Data...\n";
}
