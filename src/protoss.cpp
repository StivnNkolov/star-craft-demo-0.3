#include "../includes/protoss.h"
#include "../includes/carrier.h"
#include "../includes/phoenix.h"

Protoss::Protoss(const std::string &name) : Race(name) {
    m_shipsBuilderMapper.emplace(CarrierConstants::CARRIER_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Carrier); });
    m_shipsBuilderMapper.emplace(PhoenixConstants::PHOENIX_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Phoenix); });
}

void Protoss::attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) {
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
        if (m_fleet[shipId]->GetName() == CarrierConstants::CARRIER_NAME && !m_fleet[shipId]->GetIsDoneShooting()) {
            shipId--;
        }
    }
}