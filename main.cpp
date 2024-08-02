#include <iostream>

#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;

int main() {
    int loggedInUserId = 0;
    char choice;

    BudgetMainApp budgetMainApp;

    while (true) {
        if (loggedInUserId == 0) {
            choice = Utils::chooseOptionFromMainMenu();
            switch (choice) {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                loggedInUserId = budgetMainApp.loginUser();
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
                break;
            case '2':
                break;
            case '3':
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
                loggedInUserId = 0;
                break;
            }
        }
    }
    return 0;
}

