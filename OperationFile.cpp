#include "OperationFile.h"

void OperationFile::addOperationToFile(const Operation &operation) {

    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Root");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);

    string formattedAmount = Utils::formatToTwoDecimalPlaces(operation.amount);
    xml.AddElem("amount", formattedAmount);

    xml.Save(FILE_NAME);
}

vector <Operation> OperationFile::loadOperationsFromFile(int loggedUserId) {
    Operation operation;
    vector <Operation> operations;

    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation")) {
        xml.IntoElem();

        xml.FindElem("id");
        operation.id = stoi(xml.GetData());

        xml.FindElem("userId");
        int userId = stoi(xml.GetData());

        if(userId == loggedUserId) {
        operation.userId = userId;

            xml.FindElem("date");
            operation.date = stoi(xml.GetData());

            xml.FindElem("item");
            operation.item = xml.GetData();

            xml.FindElem("amount");
            operation.amount = stod(xml.GetData());

            operations.push_back(operation);
        }
        xml.OutOfElem();
    }
    return operations;
}
