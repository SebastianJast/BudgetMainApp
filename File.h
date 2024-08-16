#ifndef FILE_H
#define FILE_H

#include "OperationFile.h"

class File : public OperationFile {

    string INCOME_FILE_NAME;
    string EXPENSE_FILE_NAME;

public:
    File(string incomeFileName, string expenseFileName);

    void addOperationToFileIncome(const Operation &income);
    vector<Operation> loadOperationsFromFileIncome(int loggedUserId);

    void addOperationToFileExpense(const Operation &expense);
    vector<Operation> loadOperationsFromFileExpense(int loggedUserId);
};

#endif
