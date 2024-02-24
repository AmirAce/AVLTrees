#pragma once
#include "ErrorCheck.h"
#include <iostream>
#include <stack>
#include <queue>

#include <fstream>
#include <string>


using namespace std;

// public:
// Constructor that takes an ifstream


bool ErrorCheck::isSpacingValid(std::string line)
{
    if (line[1]== ' ') {
       
        return true;
    }
    
    return false;
}

bool ErrorCheck::isTypeValid(std::string line)
{
    if (line.find(".txt") != string::npos) {
        return  true;
    }
 
    
    return false;
}
