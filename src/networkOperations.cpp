//
// Created by nn5h on 7/10/19.
//
#include <iostream>
#include "NetworkOperations.h"
#include "cpr/payload.h"


int mypost(std::string url, std::map<std::string, std::string> data) {
    auto payload = cpr::Payload{{}};
    std::map<std::string, std::string>::iterator it;
    for (it = data.begin(); it != data.end(); ++it){
        payload.AddPair({it->first, it->second});
    }
    auto response = cpr::Post(url, payload);

    return response.status_code;

}

cpr::Response myget(std::string url) {
    auto urlObject = cpr::Url(url);
    auto r = cpr::Get(urlObject);

    return r;
}
