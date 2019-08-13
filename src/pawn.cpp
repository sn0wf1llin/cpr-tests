//
// Created by nn5h on 7/23/19.
//

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Pawn.h"



int Pawn::sendMyselfData() {

    return 1;
}

int Pawn::needReborn() {
    /* TEMPORARY
     * looking for parent
     * if it is, don't create clones */

    std::string url = "localhost:65501";
    auto resp = myget(url);

    if (resp.status_code == 200) {
        return 0;
    } else return 1;
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

int go() {
    std::string url = "localhost:65501";
    auto resp = myget(url);

    if (resp.status_code == 200) {
        return 0;
    } else return 1;
}

void Pawn::reborn() {
    if (needReborn() == 1) {
        // fork here
        int child1 = fork();
        std::cout << "Child 1 pid = " << getpid() << std::endl;

        int ppid = readPidFile("/tmp/pawn.pid");
        if (ppid != -1){
            // parent exists
            std::cout << ppid << std::endl;
        }
    }
}

void Pawn::doWork() {
    for (int i = 0; i < 100; i++) {
        std::cout << i << " step" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

Pawn::Pawn() {
    currentPID = getpid();

    systemData = SystemDataCollector();
    int sendSystemDataResult = sendMyselfData();


}

Pawn::~Pawn() { }
