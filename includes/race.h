#ifndef STAR_CRAFT_DEMO_0_3_RACE_H
#define STAR_CRAFT_DEMO_0_3_RACE_H

#include <functional>
#include <vector>
#include <map>
#include "ship.h"


class Race {
public:
    using ShipPtr = std::unique_ptr<Ship>;
    using ShipsPtrContainer = std::vector<ShipPtr>;
    using ShipsBuilderMap = std::map<char, std::function<void()>>;

    friend class Game;
    explicit Race(std::string name);

    virtual ~Race() = default;

    virtual void generateFleet(const std::string &fleetComposition);

    std::string GetName() const {
        return m_name;
    }

    static bool isEnemyShipKilled(Ship &enemyShip) {
        return enemyShip.GetHealth() <= 0;
    }

    static void printMsgWhenEnemyKilled(Ship &killer, size_t index, size_t killedEnemyID);


    virtual void attackEnemy(ShipsPtrContainer &defendingFleet) = 0;

protected:
    ShipsPtrContainer m_fleet;
    std::string m_name;
    ShipsBuilderMap m_shipsBuilderMapper;
};

#endif //STAR_CRAFT_DEMO_0_3_RACE_H
