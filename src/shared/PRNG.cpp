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

std::string PRNG::generateIP(std::string lowBound, std::string highBound) {
    static long double nSeed = random();

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // very hard for someone to predict what the next number is
    // going to be from the previous one.
    std::cout << "I'm your seed = " << nSeed << std::endl;
    long double v = pow(2.0, 32.0) * nSeed;
    long int first_octet = (long int)v % (long int)pow(256, 4.0);
    long int second_octet = first_octet % (long int)pow(256, 3.0);
    long int third_octet = second_octet % (long int)pow(256, 2.0);
    long int fourth_octet = third_octet % 256;

    return fmt::sprintf("%d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);
}