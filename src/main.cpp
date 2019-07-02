#include <iostream>
#include "string"
#include <stdio.h>
#include <cpr/cpr.h>
#include <map>
#include <list>
#include <cpr/curlholder.h>


int mypost(std::string url, std::map<std::string,std::string> data){
    auto payload = cpr::Payload(data);
    auto response = cpr::Post(url, payload);

    return response.status_code;

}

int myget(std::string url){
    auto urlObject = cpr::Url(url);
    auto r = cpr::Get(urlObject);
    std::cout << r.text << std::endl;

    return r.status_code;
}

int main() {
    std::string url, post_url;

    url = "http://www.example.net";
    post_url = "http://0.0.0.0:9000/";

    std::pair<std::string, std::string>& data{"user", "test"};

    int get_result = myget(url);
    int post_result = mypost(post_url, data);

    std::cout << "GET status-code: " << get_result << ".\n" << std::endl;
    return 0;
}
