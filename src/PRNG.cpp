//
// Created by nn5h on 8/16/19.
//

#include "PRNG.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


PRNG::PRNG() {}

PRNG::~PRNG() {}

int PRNG::generate() {
    // IP = [2^8 - 1].[2^8 - 1].[2^8 - 1].[2^8 - 1]
    srand(time(NULL));

    return rand() % 256;
}