#include "UserManager.h"


void UserManager::registerUser(){

    User user = enterUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);
    cout << endl << "Account created successfully"<< endl << endl;
    system("pause");
}

User UserManager::enterUserData(){
    User user;

    user.id = getNewUserId();

    string login, firstName, lastName;
    do
    {
        cout << "Enter name: ";
        firstName = Utils::readLine();
        user.firstName = firstName;

        cout << "Enter surname: ";
        lastName = Utils::readLine();
        user.lastName = lastName;

        cout << "Enter login: ";
        login = Utils::readLine();
        user.login = login;
    }
    while (checkIfLoginExist(login));

    string password;
    cout << "Enter password: ";
    password = Utils::readLine();
    user.password = password;

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().id + 1;
}

bool UserManager::checkIfLoginExist(const string &login){
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].login == login)
        {
            cout << endl << "There is a user with that login." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::loginUser() {

    User user;
    string getLogin = "", getPassword = "";

    cout << endl << "Enter login: ";
    getLogin = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> login == getLogin) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Enter the password. Attempts remaining: " << numberOfAttempts << ": ";
                getPassword = Utils::readLine();

                if (itr -> password == getPassword) {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> id;
                    return loggedUserId;
                }
            }
            cout << "The incorrect password was entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with such a login." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changeUserPassword() {
    string newPassword = "";
    cout << "Enter a new password: ";
    newPassword = Utils::readLine();

    bool passwordChanged = false;
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr->id == loggedUserId) {
            itr->password = newPassword;
            passwordChanged = true;
            break;
        }
    }

    if (passwordChanged) {
     userFile.changePasswordInFile(loggedUserId, newPassword);
        cout << "The password has been changed." << endl << endl;
    } else {
        cout << "Error: User not found." << endl;
    }

    system("pause");
}

void UserManager::logoutUser() {
    exit(0);
}

int UserManager::getLoggedUserId() {
   return loggedUserId;
}
