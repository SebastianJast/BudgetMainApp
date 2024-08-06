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

int DateMethods::convertStringDateToInt(const string &dateAsStrig){

    string strYear, strMonth, strDays, strDate;
    int dateAsInt;

    strYear = dateAsStrig.substr(0, 4);
    strMonth = dateAsStrig.substr(5, 2);
    strDays = dateAsStrig.substr(8, 2);

    strDate = strYear + strMonth + strDays;
    dateAsInt = stoi(strDate);

    return dateAsInt;
}
