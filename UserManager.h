#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager {

    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    User enterUserData();
    int getNewUserId();
    bool checkIfLoginExist(const string &login);

public:
    UserManager(string userFileName) : userFile(userFileName) {
    loggedUserId = 0;
    users = userFile.loadUsersFromFile();
    }

    void registerUser();
    int loginUser();
    void changeUserPassword();
    void logoutUser();
    int getLoggedUserId();

};

#endif
