#include "UserFile.h"

void UserFile::appendUserToFile(const User &user){

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.AddElem("Name", user.firstName);
    xml.AddElem("Surname", user.lastName);

    xml.Save("users.xml");
};

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();

        xml.FindElem("UserId");
        user.id = stoi(xml.GetData());

        xml.FindElem("Login");
        user.login = xml.GetData();

        xml.FindElem("Login");
        user.login = xml.GetData();

        xml.FindElem("Password");
        user.password = xml.GetData();

        xml.FindElem("Name");
        user.firstName = xml.GetData();

        xml.FindElem("Surname");
        user.lastName = xml.GetData();

        xml.OutOfElem();

         users.push_back(user);
    }
    return users;
}

void UserFile::changePasswordInFile(int loggedId, const string &password) {
    CMarkup xml;
    bool fileExists = xml.Load("users.xml");

  if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();

        xml.FindElem("UserId");
        if (loggedId == stoi(xml.GetData())) {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", password);
            xml.Save("users.xml");
            return;
        }

        xml.OutOfElem();
    }

    cerr << "Error: User ID not found." << endl;
}
