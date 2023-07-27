#include "../includes/ship.h"
#include "../includes/constants.h"

Ship::Ship(std::string name, int healthPoints, int damage) : m_name(std::move(name)), m_healthPoints(healthPoints),
                                                                    m_damage(damage) {}

std::string Ship::returnStatsString() {
    std::string statsString = std::to_string(m_healthPoints) + MessagesTexts::HEALTH_LEFT_STRING;
    return statsString;
}