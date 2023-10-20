#include "Budget.h"

void Budget::userRegistration() {

    userManager.userRegistration();
}

void Budget::showUsers() {

    userManager.showUsers();
}

void Budget::logging() {

    userManager.logging();
}

void Budget::passwordChange() {

    userManager.passwordChange();
}

void Budget::loggingOut() {

    userManager.loggingOut();
}

void Budget::loginMenu() {

    cout << "1. Registration." << endl;
    cout << "2. Logging in." << endl;
    cout << "3. Show users." << endl;
    cout << "9. End program." << endl;
}

void Budget::userMenu() {

    cout << "1. Add income." << endl;
    cout << "2. Add expense." << endl;
    cout << "3. Show incomes." << endl;
    cout << "4. Show expenses." << endl;
    cout << "5. Show balance." << endl;
    cout << "6. Change password." << endl;
    cout << "9. Log out." << endl;
}

bool Budget::whetherUserIsLogged(){

    return userManager.whetherUserIsLogged();
}
