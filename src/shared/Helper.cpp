//
// Created by nn5h on 7/12/19.
//
#include "Helper.h"


void printDataMap(std::map<std::string, std::string> data) {
    std::map<std::string, std::string>::iterator it;

    for (it = data.begin(); it != data.end(); ++it){
        std::cout << it->first << " " << it->second << "\n";
    }

}