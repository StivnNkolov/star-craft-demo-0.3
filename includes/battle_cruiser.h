
#ifndef DEMO_BATTLE_CRUISER_H
#define DEMO_BATTLE_CRUISER_H

#include "ship.h"
#include "constants.h"

class BattleCruiser : public Ship {
public:
    explicit BattleCruiser(const std::string &name = BattleCruiserConstants::BATTLE_CRUISER_NAME, int damage = BattleCruiserConstants::BATTLE_CRUISER_DAMAGE, int healthPoints = BattleCruiserConstants::BATTLE_CRUISER_HEALTH);

    void dealDamage(std::unique_ptr<Ship> &defendingShip) override;

private:
    int m_numberOfAttacks{};

private:
    bool isYamatoCannonReady() const;

    int returnYamatoCannonDamage();
};

#endif //DEMO_BATTLE_CRUISER_H
