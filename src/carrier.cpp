#include "../includes/carrier.h"

Carrier::Carrier(const std::string &name, int damage, int healthPoints, int shield, int numberOfInterceptors)
        : ProtossShip(name, damage,
                      healthPoints, shield), m_interceptorsCount(numberOfInterceptors) {}

void Carrier::dealDamage(std::unique_ptr<Ship> &defendingShip) {
    if (isHealthFull()) {
        m_interceptorsCount = CarrierConstants::CARRIER_DAMAGED_STATUS_INTERCEPTORS;
    }
    if (m_isDoneShooting) {
        resetCarrierStats();
    }
    attackWithInterceptors(defendingShip);

    if (m_isDoneShooting) {
        regenerateShield(CarrierConstants::CARRIER_SHIELD_REGENERATE_RATE, CarrierConstants::CARRIER_SHIELD);
    }
}


void Carrier::regenerateShield(int shieldToRegenerate, int maxPossibleShield) {
    ProtossShip::regenerateShield(shieldToRegenerate, maxPossibleShield);
}

bool Carrier::isHealthFull() {
    return m_healthPoints < CarrierConstants::CARRIER_HEALTH;
}

void Carrier::resetCarrierStats() {
    m_shotsFired = CommonConstants::MINIMUM_BOUNDARIES;
    m_isDoneShooting = false;
}

void Carrier::attackWithInterceptors(std::unique_ptr<Ship> &defendingShip) {
    while (true) {
        if (m_shotsFired == m_interceptorsCount) {
            m_shotsFired = CommonConstants::MINIMUM_BOUNDARIES;
            m_isDoneShooting = true;
            break;
        }
        defendingShip->takeDamage(m_damage);
        m_shotsFired++;
        if (defendingShip->GetHealth() <= CommonConstants::MINIMUM_BOUNDARIES) {
            break;
        }
    }
}