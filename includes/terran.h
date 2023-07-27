#ifndef DEMO_TERRAN_H
#define DEMO_TERRAN_H

#include "race.h"
#include "constants.h"

class Terran : public Race {

public:
    explicit Terran(const std::string &name = TerranConstants::TERRAN_NAME);

    void attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) override;
};

#endif //DEMO_TERRAN_H
