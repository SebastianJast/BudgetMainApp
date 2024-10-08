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

    tempAmount = CashMethods::formatAmount(tempAmount);
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

    tempAmount = CashMethods::formatAmount(tempAmount);
    expense.amount = stod(tempAmount);

    return expense;
}

void BudgetManager::showCurrentMonthBalance() {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    int currentMonthFirstDayDate = DateMethods::getCurrentMonthFirstDayDate();
    int currentDate = DateMethods::getCurrentDate();

    cout << endl;
    cout << "Incomes for the current month:" << endl;

    for (Operation& income : incomes) {
        int incomeDate = income.date;
        if(incomeDate >= currentMonthFirstDayDate && incomeDate <= currentDate) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(incomeDate)
                 << ", Item: " << income.item
                 << ", Amount: " << income.amount << endl;
            totalIncome += income.amount;
        }
    }

    cout << "Total income: " << totalIncome << endl << endl;

    cout << "Expenses for the current month:" << endl;

    for (Operation& expense : expenses) {
        int expenseDate = expense.date;
        if(expenseDate >= currentMonthFirstDayDate && expenseDate <= currentDate) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(expenseDate)
                 << ", Item: " << expense.item
                 << ", Amount: " << expense.amount << endl;
            totalExpense += expense.amount;
        }
    }

    cout << "Total expense: " << totalExpense << endl << endl;

    system("pause");
}

void BudgetManager::showPreviousMonthBalance() {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    int previousMonthFirstDayDate = DateMethods::getPreviousMonthFirstDayDate();
    int previousMonthLastDayDate = DateMethods::getPreviousMonthLastDayDate();

    cout << endl;
    cout << "Incomes for the current month:" << endl;

    for (Operation& income : incomes) {
        int incomeDate = income.date;
        if(incomeDate >= previousMonthFirstDayDate && incomeDate <= previousMonthLastDayDate) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(incomeDate)
                 << ", Item: " << income.item
                 << ", Amount: " << income.amount << endl;
            totalIncome += income.amount;
        }
    }

    cout << "Total income: " << totalIncome << endl << endl;

    cout << "Expenses for the current month:" << endl;

    for (Operation& expense : expenses) {
        int expenseDate = expense.date;
        if(expenseDate >= previousMonthFirstDayDate && expenseDate <= previousMonthLastDayDate) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(expenseDate)
                 << ", Item: " << expense.item
                 << ", Amount: " << expense.amount << endl;
            totalExpense += expense.amount;
        }
    }

    cout << "Total expense: " << totalExpense << endl << endl;

    system("pause");
}

void BudgetManager::showCustomPeriodBalance() {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    string startDate, endDate;
    int startDateInt, endDateInt;

    do {
        cout << "Enter start date (YYYY-MM-DD): ";
        cin >> startDate;
    } while (!DateMethods::validateDate(startDate));

    do {
        cout << "Enter end date (YYYY-MM-DD): ";
        cin >> endDate;
    } while (!DateMethods::validateDate(endDate));

    startDateInt = DateMethods::convertStringDateToInt(startDate);
    endDateInt = DateMethods::convertStringDateToInt(endDate);

    cout << endl;
    cout << "Incomes from " << startDate << " to " << endDate << ":" << endl;

    for (Operation& income : incomes) {
        int incomeDate = income.date;
        if(incomeDate >= startDateInt && incomeDate <= endDateInt) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(incomeDate)
                 << ", Item: " << income.item
                 << ", Amount: " << income.amount << endl;
            totalIncome += income.amount;
        }
    }

    cout << "Total income: " << totalIncome << endl << endl;

    cout << "Expenses from " << startDate << " to " << endDate << ":" << endl;

    for (Operation& expense : expenses) {
        int expenseDate = expense.date;
        if(expenseDate >= startDateInt && expenseDate <= endDateInt) {
            cout << "Date: " << DateMethods::convertIntDateToStringWithDashes(expenseDate)
                 << ", Item: " << expense.item
                 << ", Amount: " << expense.amount << endl;
            totalExpense += expense.amount;
        }
    }

    cout << "Total expense: " << totalExpense << endl << endl;

    system("pause");
}
