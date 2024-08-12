#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Utils.h"
#include "Markup.h"

using namespace std;

class UserFile {
    const string FILE_NAME;

public:
    UserFile(const string& userFileName) : FILE_NAME(userFileName) {};

    void appendUserToFile(const User &user);
    vector <User>loadUsersFromFile();
    void changePasswordInFile(int id, const string &password);
};

#endif
