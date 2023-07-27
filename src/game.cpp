#include "../includes/game.h"

Game::Game() {
    m_races.emplace_back(new Terran);
    m_races.emplace_back(new Protoss);
}

int Game::playGame() {
    printMenu();
    generateRacesFleets();
    startBattle();
    return 0;
}

void Game::printMenu() {
    std::cout << MessagesTexts::WELCOME_MESSAGE << std::endl;

}

void Game::printLastAttackedShipStats(Race &defendingRace, size_t lastShipInFleetId) {
    std::cout << MessagesTexts::LAST_STRING << defendingRace.GetName() << MessagesTexts::AIRSHIP_ID_STRING << lastShipInFleetId
              << MessagesTexts::HAS_STRING << defendingRace.m_fleet[lastShipInFleetId]->returnStatsString();
}

void Game::generateRacesFleets() {
    for (auto &race: m_races) {
        std::string currentRaceComposition;
        std::cout << MessagesTexts::ENTER_COMPOSITION_STRING << race->GetName() << std::endl;
        std::cin >> currentRaceComposition;
        race->generateFleet(currentRaceComposition);
    }
}

void Game::printWinMessage(std::unique_ptr<Race> &winningRace) {
    std::cout << winningRace->GetName() << MessagesTexts::HAS_WON_STRING << std::endl;

}

int Game::startBattle() {
    while (true) {
        for (size_t i = 0; i < m_races.size(); i++) {
            auto &attackingRace = m_races[i];
            for (size_t j = 0; j < m_races.size(); j++) {

                if (j == i) {
                    continue;
                }

                auto &defendingFleet = m_races[j]->m_fleet;
                attackingRace->attackEnemy(defendingFleet);

                if (defendingFleet.empty()) {
                    printWinMessage(attackingRace);
                    return 0;
                }
                printLastAttackedShipStats(*m_races[j], defendingFleet.size() - 1);
            }
        }
    }
}