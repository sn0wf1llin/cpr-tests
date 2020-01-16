//
// Created by nn5h on 8/16/19.
//

#include "PRNG.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>
#include <fmt/printf.h>


#include <iostream>


PRNG::PRNG() {}

PRNG::~PRNG() {}

std::string PRNG::generateIP(std::string lowBound = "0.0.0.0", std::string highBound = "255.255.255.254") {
    // LFSR

    

    return fmt::sprintf("%d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);
}