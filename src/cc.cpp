//
// Created by nn5h on 8/16/19.
//
#include <iostream>
#include <string>
#include <unistd.h>
#include "CC.h"


std::string CC::getMachineIP(){
    // get main interface IP address
    std::string ip = "0.0.0.0";
    return ip;
}

std::string CC::getMachineName(){
    // get hostname
    std::string name = "TEST CC";
    return name;
}

std::string CC::getIP(){
    return IP;
}

std::string CC::getName(){
    return name;
}

void CC::setIP(std::string newIP){
    IP = newIP;
}

void CC::setName(std::string newName){
    name = newName;
}

std::string CC::createCommand(){
    return "";
}

bool CC::sendCommand(std::string command){
    return true;
}



CC::CC(){
    IP = getMachineIP();
    name = getMachineName();
}

CC::CC(std::string ccName) {
    setIP(getMachineIP());
    setName(ccName);
}

CC::CC(std::string ccIP, std::string ccName) {
    setIP(ccIP);
    setName(ccName);
}

CC::~CC(){
    std::cout << "Destruct of " << name << " ( " << IP << " ) ...\n" << std::endl;
}