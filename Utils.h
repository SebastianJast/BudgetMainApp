#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

class Utils {
public:
    static string readLine();
    static char readChar();
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static char chooseOptionFromIncomeMenu();
    static string formatToTwoDecimalPlaces(double value);
   };

#endif
