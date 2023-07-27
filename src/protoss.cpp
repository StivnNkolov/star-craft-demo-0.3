#include "../includes/protoss.h"
#include "../includes/carrier.h"
#include "../includes/phoenix.h"

Protoss::Protoss(const std::string &name) : Race(name) {
    m_shipsBuilderMapper.emplace(CarrierConstants::CARRIER_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Carrier); });
    m_shipsBuilderMapper.emplace(PhoenixConstants::PHOENIX_COMPOSITION_CHAR, [&]() { m_fleet.emplace_back(new Phoenix); });
}

void Protoss::attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) {
    for (size_t i = 0; i < m_fleet.size(); i++) {
        if (defendingFleet.empty()) {
            return;
        }
        m_fleet[i]->dealDamage(defendingFleet[defendingFleet.size() - 1]);
        if (isEnemyShipKilled(*defendingFleet[defendingFleet.size() - 1])) {
            printMsgWhenEnemyKilled(*m_fleet[i], i, defendingFleet.size() - 1);
            defendingFleet.erase(defendingFleet.cend());
        }
        if (m_fleet[i]->GetName() == CarrierConstants::CARRIER_NAME && !m_fleet[i]->GetIsDoneShooting()) {
            i--;
        }
    }
}