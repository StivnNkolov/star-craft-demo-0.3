#include "../includes/battle_cruiser.h"

BattleCruiser::BattleCruiser(const std::string &name, int damage, int healthPoints) : Ship(name, damage,
                                                                                           healthPoints) {}

void BattleCruiser::dealDamage(std::unique_ptr<Ship> &defendingShip) {
    m_numberOfAttacks++;
    int damageToDeal = m_damage;
    if (isYamatoCannonReady()) {
        m_numberOfAttacks = CommonConstants::MINIMUM_BOUNDARIES;
        damageToDeal = returnYamatoCannonDamage();

    }

    defendingShip->takeDamage(damageToDeal);
}

bool BattleCruiser::isYamatoCannonReady() const {
    return m_numberOfAttacks == BattleCruiserConstants::YAMATO_CANNON_LOADING_TURNS;
}

int BattleCruiser::returnYamatoCannonDamage() {
    return m_damage * BattleCruiserConstants::YAMATO_CANNON_DAMAGE_MULTIPLIER;
}
