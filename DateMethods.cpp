#include "DateMethods.h"

void DateMethods::calculateCurrentDate(map<string, int>& currentDate) {
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;
}

bool DateMethods::isYearLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool DateMethods::validateDate(string &date) {
    int year, month, day;
    map<string, int> currentDate;
    stringstream ss;

    calculateCurrentDate(currentDate);

    if (date == "t" || date == "T") {
        ss << currentDate["year"] << "-" << (currentDate["month"] < 10 ? "0" : "") <<currentDate["month"] << "-" << (currentDate["day"] < 10 ? "0" : "") <<currentDate["day"];
        date = ss.str();
        return true;
    }

    if (date.length() !=10) {
        cout << "Incorrect date format. Try again." << endl;
        return false;
    }

    if(!regex_match(date, regex("[0-9]{4}-[0-9]{2}-[0-9]{2}"))) {
        cout << "Incorrect date format. Try again." << endl;
        return false;
    }

    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
        return false;
    }

    if(year < 2000 || year > currentDate["year"]) {
        cout << "Invalid year. Try again." << endl;
        return false;
    }

    if(month < 1 || month > 12 || (year == currentDate["year"] && month > currentDate["month"])) {
        cout << "Invalid month. Try again." << endl;
        return false;
    }

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(day > 31) {
            cout << "Invalid day. Try again." << endl;
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(day > 30) {
            cout << "Invalid day. Try again." << endl;
            return false;
        }
        break;
    case 2:
        if (isYearLeap(year)) {
            if(day >29) {
                cout << "Invalid day. Try again." << endl;
                return false;
            }
        } else {
            if (day > 28) {
                cout << "Invalid day. Try again." << endl;
                return false;
            }
        }
        break;
    default:
        cout << "Invalid day. Try again." << endl;
        return false;
    }
    return true;
}

int DateMethods::convertStringDateToInt(const string &dateAsString){

    string strYear, strMonth, strDays, strDate;
    int dateAsInt;

    strYear = dateAsString.substr(0, 4);
    strMonth = dateAsString.substr(5, 2);
    strDays = dateAsString.substr(8, 2);

    strDate = strYear + strMonth + strDays;
    dateAsInt = stoi(strDate);

    return dateAsInt;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt) {

    string dateAsString, strYear, strMonth, strDays, dateAsStringWithDash;
    stringstream ss;
    ss << dateAsInt;
    dateAsString = ss.str();

    strYear = dateAsString.substr(0, 4);
    strMonth = dateAsString.substr(4, 2);
    strDays = dateAsString.substr(6, 2);

    dateAsStringWithDash = strYear + "-" + strMonth + "-" + strDays;

    return dateAsStringWithDash;
}

int DateMethods::getCurrentDate(){
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    string yearAsString, monthAsString, dayAsString, dateAsString;
    int currentDateAsInt;

    stringstream yearStream;
    yearStream <<  currentDate["year"];
    yearAsString = yearStream.str();

    stringstream monthStream;
    monthStream <<  (currentDate["month"] < 10 ? "0" : "") <<currentDate["month"];
    monthAsString = monthStream.str();

    stringstream dayStream;
    dayStream <<  (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
    dayAsString = dayStream.str();

    dateAsString = yearAsString + monthAsString + dayAsString;

    currentDateAsInt = stoi(dateAsString);

    return currentDateAsInt;
}

int DateMethods::getCurrentMonthFirstDayDate(){
    map<string, int> currentDate;
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentTm.tm_mday = 1;
    currentTm.tm_hour = 0;
    currentTm.tm_min = 0;
    currentTm.tm_sec = 0;

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;

    string yearAsString, monthAsString, dayAsString, dateAsString;
    int currentMonthFirstDayDate;

    stringstream yearStream;
    yearStream <<  currentDate["year"];
    yearAsString = yearStream.str();

    stringstream monthStream;
    monthStream <<  (currentDate["month"] < 10 ? "0" : "") <<currentDate["month"];
    monthAsString = monthStream.str();

    stringstream dayStream;
    dayStream <<  (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
    dayAsString = dayStream.str();


    dateAsString = yearAsString + monthAsString + dayAsString;

    currentMonthFirstDayDate = stoi(dateAsString);

    return currentMonthFirstDayDate;
}

int DateMethods::getPreviousMonthLastDayDate(){
    map<string, int> currentDate;
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentTm.tm_mday = 1;
    currentTm.tm_hour = 0;
    currentTm.tm_min = 0;
    currentTm.tm_sec = 0;

    time_t lastday = mktime(&currentTm);
    lastday -= 86400;
    currentTm = *localtime(&lastday);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;

    string yearAsString, monthAsString, dayAsString, dateAsString;
    int previousMonthLastDayDate;

    stringstream yearStream;
    yearStream <<  currentDate["year"];
    yearAsString = yearStream.str();

    stringstream monthStream;
    monthStream <<  (currentDate["month"] < 10 ? "0" : "") <<currentDate["month"];
    monthAsString = monthStream.str();

    stringstream dayStream;
    dayStream <<  (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
    dayAsString = dayStream.str();

    dateAsString = yearAsString + monthAsString + dayAsString;

    previousMonthLastDayDate = stoi(dateAsString);

    return previousMonthLastDayDate;
}

int DateMethods::getPreviousMonthFirstDayDate(){
    map<string, int> currentDate;
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentTm.tm_mday = 1;
    currentTm.tm_hour = 0;
    currentTm.tm_min = 0;
    currentTm.tm_sec = 0;

  if(currentTm.tm_mon == 0) {
        currentTm.tm_mon = 11;
        currentTm.tm_year -= 1;
    } else {
        currentTm.tm_mon -= 1;
    }

     mktime(&currentTm);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;

    string yearAsString, monthAsString, dayAsString, dateAsString;
    int previousMonthFirstDayDate;

    stringstream yearStream;
    yearStream <<  currentDate["year"];
    yearAsString = yearStream.str();

    stringstream monthStream;
    monthStream <<  (currentDate["month"] < 10 ? "0" : "") <<currentDate["month"];
    monthAsString = monthStream.str();

    stringstream dayStream;
    dayStream <<  (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
    dayAsString = dayStream.str();

    dateAsString = yearAsString + monthAsString + dayAsString;

    previousMonthFirstDayDate = stoi(dateAsString);

    return previousMonthFirstDayDate;
}
