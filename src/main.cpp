#include <iostream>
#include "string"
#include <stdio.h>
#include "NetworkOperations.h"



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
