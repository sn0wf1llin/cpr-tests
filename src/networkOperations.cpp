//
// Created by nn5h on 7/10/19.
//

#include "NetworkOperations.h"


int mypost(std::string url, std::map<std::string, std::string> data) {
    auto payload = cpr::Payload(data);
    auto response = cpr::Post(url, payload);

    return response.status_code;

}

int myget(std::string url) {
    auto urlObject = cpr::Url(url);
    auto r = cpr::Get(urlObject);
    std::cout << r.text << std::endl;

    return r.status_code;
}
