#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "Utils.h"
#include "Markup.h"

using namespace std;

class OperationFile
{
const string INCOME_FILE_NAME;
const string EXPENSE_FILE_NAME;

public:
    OperationFile(string incomeFileName, string expenseFileName) : INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {};

    vector <Operation> loadOperationsFromFileIncome(int loggedUserId);
    void addOperationToFileIncome(const Operation &income);
    vector <Operation> loadOperationsFromFileExpense(int loggedUserId);
    void addOperationToFileExpense(const Operation &expense);

};

#endif
