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

    cout << "1. TO BE CONTINUED" << endl;
    cout << "8. Log out." << endl;
}

bool Budget::whetherUserIsLogged(){

    return userManager.whetherUserIsLogged();
}
