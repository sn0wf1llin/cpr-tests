//
// Created by nn5h on 7/11/19.
//

#ifndef UNDETECTED_COLLECTSYSTEMDATA_H
#define UNDETECTED_COLLECTSYSTEMDATA_H

#include <map>

class SystemDataCollector {
    std::string computerName;
    std::string computerIP;
    std::map<std::string, std::string> hwInfo;



public:
    SystemDataCollector();
    ~SystemDataCollector();
    std::string getIP();
    std::string getComputerName();
    std::map<std::string, std::string> getHWInfo();
    void updateIP();
    void updateHWInfo();

};

#endif //UNDETECTED_COLLECTSYSTEMDATA_H
