#include "File.h"

File::File(string incomeFileName, string expenseFileName)
    : OperationFile(""), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {}

void File::addOperationToFileIncome(const Operation &income) {
    FILE_NAME = INCOME_FILE_NAME;
    addOperationToFile(income);
}

vector<Operation> File::loadOperationsFromFileIncome(int loggedUserId) {
    FILE_NAME = INCOME_FILE_NAME;
    return loadOperationsFromFile(loggedUserId);
}

void File::addOperationToFileExpense(const Operation &expense) {
    FILE_NAME = EXPENSE_FILE_NAME;
    addOperationToFile(expense);
}

vector<Operation> File::loadOperationsFromFileExpense(int loggedUserId) {
    FILE_NAME = EXPENSE_FILE_NAME;
    return loadOperationsFromFile(loggedUserId);
}
