#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include <vector>

#include "UserManager.h"

using namespace std;

class BudgetMainApp {

   UserManager userManager;

public:

    void registerUser();
    int loginUser();
    void changeUserPassword();
    void logoutUser();

};

#endif
