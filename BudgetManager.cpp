#include "BudgetManager.h"

void BudgetManager::addIncome() {

    Operation income = enterIncomeData();

    incomes.push_back(income);
    operationFile.addOperationToFileIncome(income);
}

int BudgetManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().id + 1;
}

Operation BudgetManager::enterIncomeData() {

    Operation income;
    string  tempDate, tempAmount;

    income.userId = LOGGED_USER_ID;
    income.id = getNewIncomeId();

    do {
        cout << endl;
        cout << "Enter income date. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
    } while (!DateMethods::validateDate(tempDate));

    income.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter income name: ";
   income.item = Utils::readLine();

    do {
        cout << "Add income amount with up to two decimal places: ";
        tempAmount = Utils::readLine();
    } while (!CashMethods::validateAmount(tempAmount));

   income.amount = stod(tempAmount);


    return income;
}

void BudgetManager::addExpense() {

    Operation expense = enterExpenseData();

    expenses.push_back(expense);
    operationFile.addOperationToFileExpense(expense);
}

int BudgetManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().id + 1;
}

Operation BudgetManager::enterExpenseData() {

    Operation expense;
    string  tempDate, tempAmount;

    expense.userId = LOGGED_USER_ID;
    expense.id = getNewExpenseId();

    do {
        cout << endl;
        cout << "Enter expense date. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
    } while (!DateMethods::validateDate(tempDate));

    expense.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter expense name: ";
   expense.item = Utils::readLine();

    do {
        cout << "Add expense amount with up to two decimal places: ";
        tempAmount = Utils::readLine();
    } while (!CashMethods::validateAmount(tempAmount));

   expense.amount = stod(tempAmount);


    return expense;
}

