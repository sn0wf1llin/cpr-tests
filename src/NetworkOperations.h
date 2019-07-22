//
// Created by nn5h on 7/10/19.
//

#ifndef UNDETECTED_NETWORKOPERATIONS_H
#define UNDETECTED_NETWORKOPERATIONS_H

#include <cpr/cpr.h>
#include <map>
#include <list>
#include <cpr/curlholder.h>

int mypost(std::string url, std::map<std::string, std::string> data);
cpr::Response myget(std::string url);

#endif //UNDETECTED_NETWORKOPERATIONS_H
