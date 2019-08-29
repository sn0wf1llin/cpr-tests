//
// Created by nn5h on 8/16/19.
//

#ifndef UNDETECTED_PRNG_H
#define UNDETECTED_PRNG_H


#include <string>

class PRNG {
public:
    PRNG();
    ~PRNG();
    std::string generateIP(std::string lowBound, std::string highBound);
};


#endif //UNDETECTED_PRNG_H
