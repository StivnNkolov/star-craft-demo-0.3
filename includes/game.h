#ifndef DEMO_GAME_H
#define DEMO_GAME_H

#include <memory>
//#include <vector>
//#include "protoss.h"
//#include "terran.h"
#include "race.h"


class Game {
public:
    using RacePtr = std::unique_ptr<Race>;
    using RacesPtrContainer = std::vector<RacePtr>;
    Game();

    int playGame();

private:
    RacesPtrContainer m_races;
private:
    static void printMenu();

    static void printLastAttackedShipStats(Race &defendingRace, size_t lastShipInFleetId);

    void generateRacesFleets();

    static void printWinMessage(RacePtr &winningRace);

    int startBattle();
};

#endif //DEMO_GAME_H
