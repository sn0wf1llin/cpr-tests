//
// Created by nn5h on 7/11/19.
//

#ifndef UNDETECTED_COLLECTSYSTEMDATA_H
#define UNDETECTED_COLLECTSYSTEMDATA_H

#include <map>

class SystemDataCollector {
    std::string computerName;
    std::string computerLocalIP;
    std::string computerLocalBroadcast;
    
    std::string computerPublicIP;
    std::map<std::string, std::string> hwInfo;



public:
    SystemDataCollector();
    ~SystemDataCollector();
    void initLocalIPData();
    void initPublicIP();
    std::string getLocalIP();
    std::string getLocalIPBroadcast();
    std::string getPublicIP();
    std::string getComputerName();
    std::map<std::string, std::string> getHWInfo();
    void updateIPInfo();
    void updateHWInfo();

};

#endif //UNDETECTED_COLLECTSYSTEMDATA_H
