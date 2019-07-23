//
// Created by nn5h on 7/11/19.
//

#include "CollectSystemData.h"
#include "NetworkOperations.h"
#include <sys/types.h>
#include <ifaddrs.h>

#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>


SystemDataCollector::SystemDataCollector() {
    // init IP
    initLocalIPData();
    initPublicIP();

    // computer name
    computerName = "testing name";

    // init hwInfo
    hwInfo.insert(std::pair<std::string, std::string>("cpu", "intel"));
    hwInfo.insert(std::pair<std::string, std::string>("graphics", "nvidia"));
    hwInfo.insert(std::pair<std::string, std::string>("sound", "N/A"));
}

SystemDataCollector::~SystemDataCollector() {}

void SystemDataCollector::initLocalIPData() {
    computerLocalIP = "";
    computerLocalBroadcast = "";

    std::string ifacesIdentifiers[2] = {"eth", "enp"};

    struct ifaddrs *interfaces, *ifa;
    char host[NI_MAXHOST];
    int family, s, n;

    if (getifaddrs(&interfaces) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa=interfaces, n=0; ifa != nullptr; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;
        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr,
                            sizeof(struct sockaddr_in),
                            host,
                            NI_MAXHOST,
                            NULL,
                            0,
                            NI_NUMERICHOST);

            if (s == 0) {
                for (int j = 0; j < ifacesIdentifiers->size(); j++){
                    if (std::string(ifa->ifa_name).find(ifacesIdentifiers[j]) != std::string::npos){
                        computerLocalIP = host;
                        computerLocalBroadcast = inet_ntoa(((struct sockaddr_in *) ifa->ifa_netmask)->sin_addr);
                    }
                }
            }
        }
    }

}

void SystemDataCollector::initPublicIP() {
    try {
        auto res = myget("https://suip.biz/ip/");
        computerPublicIP = res.text;
    }
    catch (const std::exception & e) {
        computerPublicIP = "256.256.256.256";
    }
}

std::string SystemDataCollector::getLocalIP() {

    return computerLocalIP;
}

std::string SystemDataCollector::getLocalIPBroadcast() {

    return computerLocalBroadcast;
}

std::string SystemDataCollector::getPublicIP() {

    return computerPublicIP;
}

std::string SystemDataCollector::getComputerName() {
    return computerName;
}

std::map<std::string, std::string> SystemDataCollector::getHWInfo() {
    return hwInfo;
}

void SystemDataCollector::updateIPInfo() {
    initLocalIPData();
    initPublicIP();
}

void SystemDataCollector::updateHWInfo() {
    delete &hwInfo;

    std::map<std::string, std::string> hwInfo;
    hwInfo.insert(std::pair<std::string, std::string>("cpu", "updated: intel"));
    hwInfo.insert(std::pair<std::string, std::string>("graphics", "updated: nvidia"));
    hwInfo.insert(std::pair<std::string, std::string>("sound", "updated: cool"));

}