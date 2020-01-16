//
// Created by nn5h on 8/16/19.
//

#ifndef UNDETECTED_PRNG_H
#define UNDETECTED_PRNG_H


#include <string>

class PRNG {
    // as CC can homehow spread itself => IP is not a <predictable value> in the any way
    // so IP will generates as is, just numbers
    // may be correct this concept when a new idea appeared
public:
    PRNG();
    ~PRNG();
    std::string generateIP(std::string lowBound, std::string highBound);
};


#endif //UNDETECTED_PRNG_H
