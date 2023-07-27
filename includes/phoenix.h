
#ifndef DEMO_PHOENIX_H
#define DEMO_PHOENIX_H

#include "protoss_ship.h"
#include "constants.h"

class Phoenix : public ProtossShip {
public:
    explicit Phoenix(const std::string &name = PhoenixConstants::PHOENIX_NAME,
                     int damage = PhoenixConstants::PHOENIX_DAMAGE, int healthPoints = PhoenixConstants::PHOENIX_HEALTH,
                     int shield = PhoenixConstants::PHOENIX_SHIELD);

    void dealDamage(std::unique_ptr<Ship> &defendingShip) override;

private:
    void regenerateShield(int shieldToRegenerate, int maxPossibleShield) override;

};

#endif //DEMO_PHOENIX_H
