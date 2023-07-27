#include "../includes/terran.h"
#include "../includes/viking.h"

Terran::Terran(const std::string &name) : Race(name) {
    m_shipsBuilderMapper.emplace(VikingConstants::VIKING_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Viking); });
    m_shipsBuilderMapper.emplace(BattleCruiserConstants::BATTLE_CRUISER_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new BattleCruiser); });
}

void Terran::attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) {
    for (size_t i = 0; i < m_fleet.size(); i++) {
        if (defendingFleet.empty()) {
            return;
        }
        m_fleet[i]->dealDamage(defendingFleet[defendingFleet.size() - 1]);
        if (isEnemyShipKilled(*defendingFleet[defendingFleet.size() - 1])) {
            printMsgWhenEnemyKilled(*m_fleet[i], i, defendingFleet.size() - 1);
            defendingFleet.erase(defendingFleet.cend());
        }

    }
}