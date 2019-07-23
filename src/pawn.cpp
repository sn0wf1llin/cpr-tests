//
// Created by nn5h on 7/23/19.
//

#include "Pawn.h"

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


Pawn::Pawn() {
    currentPID = getpid();

    systemData = SystemDataCollector();
    int sendSystemDataResult = sendMyselfData();
    reborn();
    doWork();

}

Pawn::~Pawn() {
    rmPidFile();
}

int Pawn::sendMyselfData() {

    return 1;
}

int Pawn::needReborn() {
    /* TEMPORARY
     * listen local conn & port
     * if it is, don't create clones */

    std::string url = "localhost:65501";
    auto resp = myget(url);

    if (resp.status_code == 200) {
        return 0;
    } else return 1;
}

int readPidFile(std::string fname) {
    std::fstream fs;

    if (fs.is_open()) {
        std::string line;
        getline(file, line);
        int gotPid = std::atoi(line);
        printf("Got %d\n", gotPid);
        fs.close();
    }

    return gotPid;
}

void Pawn::reborn() {
    if (needReborn() == 1) {
        // fork here
        int child1 = fork();
        std::cout << "Child 1 pid = " << child1 << std::endl;
        child1.
    }
}

void Pawn::doWork() {
    for (int i = 0; i < 1000; i++) {
        std::cout << i << " step" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void Pawn::pidToFile(std::string fname) {
    ofstream myfile;
    myfile.open (fname);
    myfile << currentPID;
    myfile.close();
}

void rmPidFile(std::string fname) {
    if (remove(fname)) {
        perror("Error deleting a %s", fname);
    }
}