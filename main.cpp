#include <iostream>

#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;

int main() {
    int loggedUserId = 0;
    char choice;

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml" );

    while (true) {
        if (loggedUserId == 0) {
            choice = Utils::chooseOptionFromMainMenu();
            switch (choice) {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                loggedUserId = budgetMainApp.loginUser();
                break;
            case '9':
                budgetMainApp.logoutUser();
                break;
            default:
                cout << endl << "Invalid option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = Utils::chooseOptionFromUserMenu();
            switch (choice) {
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showCurrentMonthBalance();
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                budgetMainApp.changeUserPassword();
                break;
            case '8':
                loggedUserId = 0;
                break;
            }
        }
    }
    return 0;
}

