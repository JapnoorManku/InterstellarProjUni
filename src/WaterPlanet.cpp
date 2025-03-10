#include "WaterPlanet.hpp"
#include "DialogueManager.hpp"
#include "Puzzle.hpp"
#include "Player.hpp"
#include "PlanetaryData.hpp"
#include "Tesseract.hpp"
#include "Game.hpp"

WaterPlanet::WaterPlanet()
    : Environment("Water Planet"), tidalWaveIncoming(false), timeLeft(30) {}

void WaterPlanet::enter(Player* player) {
    DialogueManager::displayMessage(
        "You are on Miller's planet now."
         "Collect planetary data and leave before the tidal wave hits.");
    DialogueManager::displayMessage
    ("Time remaining: " + std::to_string(timeLeft) + " seconds.");

    exploreLocations(player);  // Begin the exploration and challenge
}

std::string WaterPlanet::getDescription() const {
    return "This is the Water Planet."
     "Move quickly and use the Data Recorder to collect information.\n";
}

void WaterPlanet::exploreLocations(Player* player) {
    // Initialize a timed puzzle for data collection
    Puzzle* tidalWavePuzzle = new Puzzle(
        "Collect planetary data before the tidal wave strikes.",
        {},  // No binary puzzle data
        {0, 0});  // No coordinates needed for this puzzle

    DialogueManager::displayMessage(
        "Solve the timed puzzle to collect planetary data. Be quick!");

    // Start the timed sequence challenge
    bool success = tidalWavePuzzle->
    solveTimedSequence(30, 5);  // 30 seconds, 5 actions

    delete tidalWavePuzzle;  // Clean up after puzzle usage

    if (success) {
        DialogueManager::displayMessage(
            "You successfully collected the planetary data and just in time!");
        player->getInventory()->addItem
        (new PlanetaryData());  // Add data to the player's inventory

        DialogueManager::displayMessage
        ("A spatial anomaly pulls you into the Tesseract...");
        // Transition directly to the Tesseract
        Tesseract* tesseract = new Tesseract();

        // Set exits for navigation
        this->setExit("Tesseract", tesseract);
        tesseract->setExit("Water Planet", this);

        // Move the player to the Tesseract
        player->move(tesseract);
    } else {
        DialogueManager::displayMessage(
            "The tidal wave destroyed the"
             "lander. You failed to collect the data.");
        player->getGame()->gameOver
        ("The tidal wave destroyed the lander.");  // Game over
    }
}

void WaterPlanet::triggerTidalWave() {
    tidalWaveIncoming = true;
    DialogueManager::displayMessage(
        "The tidal wave is here! You"
         "have to leave immediately, or you'll die.");
    DialogueManager::displayMessage("You died. Game over!");
}
