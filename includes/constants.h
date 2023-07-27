#ifndef DEMO_CONSTANTS_H
#define DEMO_CONSTANTS_H
#include <string>

namespace BattleCruiserConstants {
    const std::string BATTLE_CRUISER_NAME = "BattleCruser";
    const char BATTLE_CRUISER_COMPOSITION_CHAR = 'b';
    const int BATTLE_CRUISER_HEALTH = 450;
    const int BATTLE_CRUISER_DAMAGE = 40;
    const int YAMATO_CANNON_LOADING_TURNS = 5;
    const int YAMATO_CANNON_DAMAGE_MULTIPLIER = 5;
}

namespace CarrierConstants {
    const std::string CARRIER_NAME = "Carrier";
    const char CARRIER_COMPOSITION_CHAR = 'c';

    const int CARRIER_HEALTH = 200;
    const int CARRIER_SHIELD = 150;
    const int CARRIER_DAMAGE = 8;
    const int CARRIER_SHIELD_REGENERATE_RATE = 40;
    const int CARRIER_MAX_INTERCEPTORS = 8;
    const int CARRIER_DAMAGED_STATUS_INTERCEPTORS = 4;
}

namespace PhoenixConstants {
    const std::string PHOENIX_NAME = "Phoenix";
    const char PHOENIX_COMPOSITION_CHAR = 'p';
    const int PHOENIX_HEALTH = 90;
    const int PHOENIX_SHIELD = 90;
    const int PHOENIX_DAMAGE = 20;
    const int PHOENIX_SHIELD_REGENERATE_RATE = 20;
}

namespace VikingConstants {
    const std::string VIKING_NAME = "Viking";
    const char VIKING_COMPOSITION_CHAR = 'v';
    const int VIKING_HEALTH = 150;
    const int VIKING_DAMAGE = 15;
    const int VIKING_DAMAGE_MULTIPLIER = 2;
}

namespace TerranConstants{
    const std::string TERRAN_NAME = "Terran";
}

namespace ProtossConstants{
    const std::string PROTOSS_NAME = "Protoss";
}

namespace MessagesTexts{
    const std::string WELCOME_MESSAGE = "Welcome to StarCraft!!";
    const std::string LAST_STRING = "Last ";
    const std::string AIRSHIP_ID_STRING = " AirShip with ID: ";
    const std::string HAS_STRING = " has ";
    const std::string ENTER_COMPOSITION_STRING = "Enter composition for ";
    const std::string HAS_WON_STRING = " has won!";
    const std::string HEALTH_AND_STRING = " health and ";
    const std::string SHIELD_LEFT_STRING = " shield left\n";
    const std::string HEALTH_LEFT_STRING = " health left\n";
    const std::string WITH_ID_STRING = " with ID: ";
    const std::string KILLED_ENEMY_SHIP_STRING = " killed enemy airship with ID: ";
}

namespace CommonConstants{
    const int MINIMUM_BOUNDARIES = 0;
}



#endif //DEMO_CONSTANTS_H
