#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <regex>

using namespace std;

class DateMethods {

public:
    static void calculateCurrentDate(map<string, int>& currentDate);
    static bool isYearLeap(int year);
    static bool validateDate(string &date);
    static int convertStringDateToInt(const string &dateAsStrig);

};

#endif
