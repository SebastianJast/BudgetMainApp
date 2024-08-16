#ifndef CASHMETHODS_H
#define CASHMETHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

class CashMethods {

public:
    static bool validateAmount(string amount);
    static string formatAmount(string amount);

};

#endif
