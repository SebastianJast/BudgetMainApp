#include "CashMethods.h"

bool CashMethods::validateAmount(string amount) {
    bool dotFound = false;
    bool commaFound = false;

    if (amount.empty()) {
        return false;
    }

    for (char c : amount) {
        if (c == ',') {
            if (commaFound || dotFound) {
                return false;
            }
            commaFound = true;
        } else if (c == '.') {
            if (dotFound) {
                return false;
            }
            dotFound = true;
        } else if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

string CashMethods::formatAmount(string amount) {
   string formattedAmount;
    bool dotFound = false;

    for (char c : amount) {
        if (c == ',') {
            formattedAmount += '.';
            dotFound = true;
        } else if (c == '.') {
            if (dotFound) {
                return "";
            }
            formattedAmount += '.';
            dotFound = true;
        } else if (isdigit(c)) {
            formattedAmount += c;
        } else {
            return "";
        }
    }

    if (!dotFound) {
        formattedAmount += ".00";
    } else {
        size_t dotPosition = formattedAmount.find('.');
        size_t lengthAfterDot = formattedAmount.length() - dotPosition - 1;

        if (lengthAfterDot < 2) {
            formattedAmount.append(2 - lengthAfterDot, '0');
        } else if (lengthAfterDot > 2) {
            formattedAmount = formattedAmount.substr(0, dotPosition + 3);
        }
    }

    return formattedAmount;
}

