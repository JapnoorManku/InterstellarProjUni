/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
 */

#ifndef TARS_H
#define TARS_H

#include <vector>
#include <string>
#include "NPC.hpp"

class TARS : public NPC {
 public:
    TARS();
    void interact(Player* player) override;
};

#endif
