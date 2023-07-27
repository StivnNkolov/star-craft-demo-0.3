#ifndef DEMO_TERRAN_H
#define DEMO_TERRAN_H

#include <vector>
#include <functional>
#include <map>
#include "race.h"
#include "battle_cruiser.h"
#include "constants.h"

class Terran : public Race {

public:
    explicit Terran(const std::string &name = TerranConstants::TERRAN_NAME);

    void attackEnemy(std::vector<std::unique_ptr<Ship>> &defendingFleet) override;
};

#endif //DEMO_TERRAN_H
