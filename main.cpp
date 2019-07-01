#include <iostream>
#include "string"
#include <stdio.h>
#include <cpr/cpr.h>
#include <map>
#include <cpr/curlholder.h>


using namespace std;

int mypost(string url, std::map<std::string,std::string> data){

    return 0;

}

int myget(std::string url){
    auto urlObject = cpr::Url(url);
    auto r = cpr::Get(urlObject);
    cout << r.text << endl;

    return r.status_code;
}

int main() {
    std::string url;

    url = "http://www.example.net";
    std::map<std::string, std::string> data;

    data["user"] = "test";
    data["password"] = "test111";

    int ger_result = myget(url);
    int post_result = mypost(url, data);

    cout << "Hello, World!" << endl;
    return 0;
}