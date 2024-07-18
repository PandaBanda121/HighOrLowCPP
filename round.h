#ifndef ROUND_H
#define ROUND_H

#include <cstdlib> 
#include <iostream>
#include <vector>
#include <string>

#include "turn.h"

using namespace std;

struct Round {
    int roundNum, quota, turns;
    Turn *turn;
};

#endif