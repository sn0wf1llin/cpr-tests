#include <iostream>
#include <string>
#include "Pawn.h"


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

//    auto dc = SystemDataCollector();
//    printf("local IP: %s \npublic IP: %s\nname: %s\n", &dc.getLocalIP()[0], &dc.getPublicIP()[0], &dc.getComputerName()[0]);

//    auto reborn = Reborn();
//    int need_reborn = reborn.needReborn();
//    printf("Need reborn: %d\n", need_reborn);

    auto p = Pawn();
    std::cout << p.systemData.getComputerName() << " " << p.systemData.getLocalIP() << std::endl;

    return 0;
}
