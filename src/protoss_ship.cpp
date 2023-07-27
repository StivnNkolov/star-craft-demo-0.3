#include <utility>

#include "../includes/protoss_ship.h"
#include "../includes/constants.h"


ProtossShip::ProtossShip(std::string name, int damage, int healthPoints, int shield) : Ship(std::move(name), damage,
                                                                                            healthPoints),
                                                                                              m_shield(shield) {}

void ProtossShip::regenerateShield(int shieldToRegenerate, int maxPossibleShield) {
    m_shield += shieldToRegenerate;
    if (m_shield > maxPossibleShield) {
        m_shield = maxPossibleShield;
    }
}

void ProtossShip::takeDamage(int dmg) {
    m_shield -= dmg;
    if (m_shield < CommonConstants::MINIMUM_BOUNDARIES) {
        m_healthPoints -= std::abs(m_shield);
        m_shield = CommonConstants::MINIMUM_BOUNDARIES;
    }
}

std::string ProtossShip::returnStatsString() {
    std::string statsString =
            std::to_string(m_healthPoints) + MessagesTexts::HEALTH_AND_STRING + std::to_string(m_shield) + MessagesTexts::SHIELD_LEFT_STRING;
    return statsString;
}