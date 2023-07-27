#include "../includes/viking.h"

Viking::Viking(const std::string &name, int damage, int healthPoints) : Ship(name, damage, healthPoints) {}

void Viking::dealDamage(std::unique_ptr<Ship> &defendingShip) {
    int damageToDeal = m_damage;
    if (defendingShip->GetName() == PhoenixConstants::PHOENIX_NAME) {
        damageToDeal = dealDoubleDamage();
    }
    defendingShip->takeDamage(damageToDeal);
}


int Viking::dealDoubleDamage() {
    return m_damage * VikingConstants::VIKING_DAMAGE_MULTIPLIER;
}

