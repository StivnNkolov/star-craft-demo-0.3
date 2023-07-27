#ifndef STAR_CRAFT_DEMO_0_3_SHIP_H
#define STAR_CRAFT_DEMO_0_3_SHIP_H

#include <memory>
#include <string>

class Ship {
public:
    Ship(std::string name, int damage, int healthPoints);

    virtual ~Ship() = default;

    virtual void takeDamage(int dmg) {
        m_healthPoints -= dmg;
    };

    virtual void dealDamage(std::unique_ptr<Ship> &defendingShip) = 0;

    std::string GetName() const {
        return m_name;
    };

    int GetDamage() const {
        return m_damage;
    }

    int GetHealth() const {
        return m_healthPoints;
    }

    virtual int GetShield() {
        return 0;
    };

    virtual bool GetIsDoneShooting() {
        return false;
    };

    virtual std::string returnStatsString();


protected:
    std::string m_name;
    int m_damage{};
    int m_healthPoints{};
};

#endif //STAR_CRAFT_DEMO_0_3_SHIP_H
