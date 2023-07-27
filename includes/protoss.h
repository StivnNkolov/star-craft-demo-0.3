#ifndef DEMO_PROTOSS_H
#define DEMO_PROTOSS_H

#include "race.h"
#include "constants.h"


class Protoss : public Race {

public:
    explicit Protoss(const std::string &name = ProtossConstants::PROTOSS_NAME);

    void attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) override;

};


#endif //DEMO_PROTOSS_H
