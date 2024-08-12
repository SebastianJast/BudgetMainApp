#include "OperationFile.h"


void OperationFile::addOperationToFileIncome(const Operation &income) {

    CMarkup xml;

    bool fileExists = xml.Load(INCOME_FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Root");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("id", income.id);
    xml.AddElem("userId", income.userId);
    xml.AddElem("date", income.date);
    xml.AddElem("item", income.item);
    xml.AddElem("amount", income.amount);

    xml.Save(INCOME_FILE_NAME);
}

vector <Operation> OperationFile::loadOperationsFromFileIncome(int loggedUserId) {
    Operation income;
    vector <Operation> incomes;

    CMarkup xml;

    bool fileExists = xml.Load(INCOME_FILE_NAME);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation")) {
        xml.IntoElem();

        xml.FindElem("id");
        income.id = stoi(xml.GetData());

        xml.FindElem("userId");
        int userId = stoi(xml.GetData());

        if(userId == loggedUserId) {
            income.userId = userId;

            xml.FindElem("date");
            income.date = stoi(xml.GetData());

            xml.FindElem("item");
            income.item = xml.GetData();

            xml.FindElem("amount");
            income.amount = stoi(xml.GetData());

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}

void OperationFile::addOperationToFileExpense(const Operation &expense) {

    CMarkup xml;

    bool fileExists = xml.Load(EXPENSE_FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Root");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("id", expense.id);
    xml.AddElem("userId", expense.userId);
    xml.AddElem("date", expense.date);
    xml.AddElem("item", expense.item);
    xml.AddElem("amount", expense.amount);

    xml.Save(EXPENSE_FILE_NAME);
}

vector <Operation> OperationFile::loadOperationsFromFileExpense(int loggedUserId) {
    Operation expense;
    vector <Operation> expenses;

    CMarkup xml;

    bool fileExists = xml.Load(EXPENSE_FILE_NAME);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation")) {
        xml.IntoElem();

        xml.FindElem("id");
        expense.id = stoi(xml.GetData());

        xml.FindElem("userId");
        int userId = stoi(xml.GetData());

        if(userId == loggedUserId) {
            expense.userId = userId;

            xml.FindElem("date");
            expense.date = stoi(xml.GetData());

            xml.FindElem("item");
            expense.item = xml.GetData();

            xml.FindElem("amount");
            expense.amount = stoi(xml.GetData());

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}



