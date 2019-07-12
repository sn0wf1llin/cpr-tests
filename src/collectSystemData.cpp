//
// Created by nn5h on 7/11/19.
//

#include "CollectSystemData.h"

SystemDataCollector::SystemDataCollector() {
    // init IP
    computerIP = "192.168.100.100";
    // computer name
    computerName = "testing name";
    // init hwInfo
    hwInfo.insert(std::pair<std::string, std::string>("cpu", "intel"));
    hwInfo.insert(std::pair<std::string, std::string>("graphics", "nvidia"));
    hwInfo.insert(std::pair<std::string, std::string>("sound", "N/A"));

}

SystemDataCollector::~SystemDataCollector() {}

std::string SystemDataCollector::getIP() {
    return computerIP;
}

std::string SystemDataCollector::getComputerName() {
    return computerName;
}

std::map<std::string, std::string> SystemDataCollector::getHWInfo() {
    return hwInfo;
}

void SystemDataCollector::updateIP() {
    std::string temp = "73.73.73.73";

    computerIP = temp;
}

void SystemDataCollector::updateHWInfo() {
    delete &hwInfo;

    std::map<std::string, std::string> hwInfo;
    hwInfo.insert(std::pair<std::string, std::string>("cpu", "updated: intel"));
    hwInfo.insert(std::pair<std::string, std::string>("graphics", "updated: nvidia"));
    hwInfo.insert(std::pair<std::string, std::string>("sound", "updated: cool"));

}