
#ifndef DEMO_CARRIER_H
#define DEMO_CARRIER_H

#include "protoss_ship.h"
#include "constants.h"


class Carrier : public ProtossShip {
public:
    explicit Carrier(const std::string &name = CarrierConstants::CARRIER_NAME,
                     int damage = CarrierConstants::CARRIER_DAMAGE, int healthPoints = CarrierConstants::CARRIER_HEALTH,
                     int shield = CarrierConstants::CARRIER_SHIELD,
                     int numberOfInterceptors = CarrierConstants::CARRIER_MAX_INTERCEPTORS);

    void dealDamage(std::unique_ptr<Ship> &defendingShip) override;

    bool GetIsDoneShooting() override {
        return m_isDoneShooting;
    };

private:
    bool m_isDoneShooting = false;

    int m_shotsFired{};

    int m_interceptorsCount{};

private:
    void regenerateShield(int shieldToRegenerate, int maxPossibleShield) override;

    bool isHealthFull();

    void resetCarrierStats();

    void attackWithInterceptors(std::unique_ptr<Ship> &defendingShip);
};

#endif //DEMO_CARRIER_H
