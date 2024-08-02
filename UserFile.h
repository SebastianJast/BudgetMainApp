#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Utils.h"
#include "Markup.h"

using namespace std;

class UserFile

{
public:
    void appendUserToFile(const User &user);
    vector <User>loadUsersFromFile();
    static void changePasswordInFile(int id, const string &password);
};

#endif
