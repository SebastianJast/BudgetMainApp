#include "CashMethods.h"

bool CashMethods::validateAmount(string amount) {
    bool valid = true;
    for (size_t i = 0; i < amount.length(); i++) {
        if (amount[i] == ',') {
            amount[i] = '.';
        } else if (!isdigit(amount[i]) && amount[i] != '.') {
            valid = false;
        }
    }
    return valid;
}
