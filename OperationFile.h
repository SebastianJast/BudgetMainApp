#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "Utils.h"
#include "Markup.h"

using namespace std;

class OperationFile {

protected:
    string FILE_NAME;

public:
    OperationFile(string fileName) : FILE_NAME(fileName) {};

    vector <Operation> loadOperationsFromFile(int loggedUserId);
    void addOperationToFile(const Operation &income);

};

#endif
