#include "Utils.h"

string Utils::readLine(){
    string enter = "";
    getline(cin, enter);
    return enter;
}

char Utils::readChar(){
    string enter = "";
    char myChar  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            myChar = enter[0];
            break;
        }
        cout << "This is not a single character. Please enter again." << endl;
    }
    return myChar;
}

char Utils::chooseOptionFromMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit Program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}

char Utils::chooseOptionFromUserMenu(){
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
//    cout << "1. Add Contact" << endl;
//    cout << "2. Search by First Name" << endl;
//    cout << "3. Search by Last Name" << endl;
//    cout << "4. Display Contacts" << endl;
//    cout << "5. Delete Contact" << endl;
//    cout << "6. Edit Contact" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change Password" << endl;
    cout << "8. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}


