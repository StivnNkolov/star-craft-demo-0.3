#include "../includes/phoenix.h"



Phoenix::Phoenix(const std::string &name, int damage, int healthPoints, int shield) : ProtossShip(name, damage,
                                                                                                  healthPoints, shield) {}

void Phoenix::dealDamage(std::unique_ptr<Ship> &defendingShip) {
    defendingShip->takeDamage(m_damage);
    regenerateShield(PhoenixConstants::PHOENIX_SHIELD_REGENERATE_RATE, PhoenixConstants::PHOENIX_SHIELD);
}


void Phoenix::regenerateShield(int shieldToRegenerate, int maxPossibleShield) {
    ProtossShip::regenerateShield(shieldToRegenerate, maxPossibleShield);
}

