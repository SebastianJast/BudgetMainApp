#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Operation.h"
#include "Utils.h"
#include "UserManager.h"
#include "DateMethods.h"
#include "File.h"
#include "CashMethods.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    vector <Operation> incomes;
    vector <Operation> expenses;
    File operationFile;

    Operation enterIncomeData();
    Operation enterExpenseData();
    int getNewIncomeId();
    int getNewExpenseId();

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) : LOGGED_USER_ID(loggedUserId), operationFile(incomeFileName, expenseFileName) {
        incomes = operationFile.loadOperationsFromFileIncome(LOGGED_USER_ID);
        expenses = operationFile.loadOperationsFromFileExpense(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};

#endif
