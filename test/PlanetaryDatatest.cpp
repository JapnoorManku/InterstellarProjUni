// #include <gtest/gtest.h>
// #include "PlanetaryData.hpp"
// #include "Player.hpp"
// #include "DialogueManager.hpp"

// // Mocking DialogueManager to suppress output during tests
// class MockDialogueManager : public DialogueManager {
//  public:
//   void setHasCoordinateMap(bool value) { hasCoordinateMap = value; }
//   Environment* movedTo;
//     static void displayMessage(const std::string& message) {
//     }
// };

// class PlanetaryDataTest : public ::testing::Test {
//  protected:
//     PlanetaryDataTest() {
//         player = new Player();
//         planetaryData = new PlanetaryData();
//     }

//     ~PlanetaryDataTest() {
//         delete player;
//         delete planetaryData;
//     }

//     Player* player;
//     PlanetaryData* planetaryData;
// };

// TEST_F(PlanetaryDataTest, TestUsePlanetaryData) {
//     EXPECT_NO_THROW(planetaryData->use(player));
// }

// TEST_F(PlanetaryDataTest, TestPlanetaryDataName) {
//     EXPECT_EQ(planetaryData->getName(), "Planetary Data");
// }

// TEST_F(PlanetaryDataTest, TestPlanetaryDataUseMessage) {
//     EXPECT_NO_THROW(planetaryData->use(player));
// }
