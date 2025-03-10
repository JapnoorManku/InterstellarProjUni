/**
 * @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
 * @date 2024-12-04
*/

#ifndef TESSERACTKEY_H
#define TESSERACTKEY_H

#include "Item.hpp"
#include "Player.hpp"

class TesseractKey : public Item {
 public:
   /**
   * @brief Constructor for TesseractKey.
   */
    TesseractKey();
      /**
   * @brief Uses the Tesseract Key.
   * @param player Pointer to the player using the item.
   */
    void use(Player* player) override;
};

#endif
