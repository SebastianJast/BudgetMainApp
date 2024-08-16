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
    cout << "1. Add Income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month's balance" << endl;
    cout << "4. Previous month's balance" << endl;
    cout << "5. Selected period's balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change Password" << endl;
    cout << "7. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}

char Utils::chooseOptionFromIncomeMenu() {
    char choice;

    system("cls");
    cout << " >>> INCOME MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add the income with today's date" << endl;
    cout << "2. Add the income with a different date." << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}

string Utils::formatToTwoDecimalPlaces(double value) {
   ostringstream oss;
    oss << fixed << setprecision(2) << value;
    return oss.str();
}



