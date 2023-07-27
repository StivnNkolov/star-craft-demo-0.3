#include "../includes/terran.h"
#include "../includes/viking.h"
#include "../includes/battle_cruiser.h"


Terran::Terran(const std::string &name) : Race(name) {
    m_shipsBuilderMapper.emplace(VikingConstants::VIKING_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Viking); });
    m_shipsBuilderMapper.emplace(BattleCruiserConstants::BATTLE_CRUISER_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new BattleCruiser); });
}

void Terran::attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) {
    for (size_t shipId = 0; shipId < m_fleet.size(); shipId++) {
        if (defendingFleet.empty()) {
            return;
        }
        size_t lastUnitId = defendingFleet.size() - 1;
        m_fleet[shipId]->dealDamage(defendingFleet[lastUnitId]);

        if (isEnemyShipKilled(*defendingFleet[lastUnitId])) {
            printMsgWhenEnemyKilled(*m_fleet[shipId], shipId, lastUnitId);
            defendingFleet.erase(defendingFleet.cend());
        }

    }
}