//#include "BudgetManager.h
//
//Operation BudgetManager::addOperationDetails(const Type &type) {
//    string typeDescription, tempDate, tempAmount;
//    Operation operation;
//
//    Menus::showTitle("ADD OPERATION DETAILS");
//
//    switch (type) {
//    case INCOME:
//        operation.id = incomeFile.getLastId() + 1;
//        typeDescription = "income";
//        break;
//    case EXPENSE:
//        operation.id = expenseFile.getLastId() + 1;
//        typeDescription = "expense";
//        break;
//    }
//
//    operation.userId = LOGGED_USER_ID;
//
//    do {
//        cout << "Enter " << typeDescription << " date. Press 't' if you want to enter current date: ";
//        tempDate = Utils::readLine();
//    } while (!DateMethods::validateDate(tempDate));
//
//    operation.date = DateMethods::convertStringDateToInt(tempDate);
//
//    cout << "Enter " << typeDescription << " name: ";
//    operation.item = Utils::readLine();
//
//    do {
//        cout << "Add " << typeDescription << " amount with up to two decimal places: ";
//        tempAmount = Utils.readLine();
//    } while (!CashMethods::validateAmount(tempAmount));
//
//    operation.amount = stod(tempAmount);
//
//    return operation;
//}
