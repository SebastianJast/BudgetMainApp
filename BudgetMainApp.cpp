#include "BudgetMainApp.h"

void BudgetMainApp::registerUser(){

userManager.registerUser();

}

int BudgetMainApp::loginUser(){

int loggedUserId = userManager.loginUser();

 if (loggedUserId > 0) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME ,loggedUserId);
    }
return loggedUserId;
}

void BudgetMainApp::changeUserPassword(){

userManager.changeUserPassword();

}

void BudgetMainApp::logoutUser() {

userManager.logoutUser();
delete budgetManager;
budgetManager = NULL;

}

void BudgetMainApp::addIncome() {

budgetManager->addIncome();

}

void BudgetMainApp::addExpense() {

budgetManager->addExpense();

}

