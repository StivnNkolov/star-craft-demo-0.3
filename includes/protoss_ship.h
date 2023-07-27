#ifndef STAR_CRAFT_DEMO_0_3_PROTOSS_SHIP_H
#define STAR_CRAFT_DEMO_0_3_PROTOSS_SHIP_H
#include "ship.h"

class ProtossShip : public Ship {
public:
    ProtossShip(std::string name, int damage, int healthPoints, int shield);

    virtual void regenerateShield(int shieldToRegenerate, int maxPossibleShield);

    int GetShield() override {
        return m_shield;
    }

    bool GetIsDoneShooting() override {
        return false;
    };

    void takeDamage(int dmg) override;

    std::string returnStatsString() override;

protected:
    int m_shield{};
};

#endif //STAR_CRAFT_DEMO_0_3_PROTOSS_SHIP_H
