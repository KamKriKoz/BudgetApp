#include "Budget.h"

void Budget::userRegistration() {

    userManager.userRegistration();
}

void Budget::showUsers() {

    userManager.showUsers();
}

void Budget::logging() {

    userManager.logging();
    if (userManager.whetherUserIsLogged()) {
        serviceManager = new ServiceManager(userManager.getIdLoggedUser());
    }
}

void Budget::passwordChange() {

    userManager.passwordChange();
}

void Budget::loggingOut() {

    userManager.loggingOut();
    delete serviceManager;
    serviceManager = NULL;
}

void Budget::addIncome(){

    if (userManager.whetherUserIsLogged()) serviceManager -> addIncome();
    else {
        cout << "You must be logged in to add a income." << endl;
        system("pause");
    }
}

void Budget::addExpense(){

    if (userManager.whetherUserIsLogged()) serviceManager -> addExpense();
    else {
        cout << "You must be logged in to add a income." << endl;
        system("pause");
    }
}

void Budget::showIncomes(){

    if (userManager.whetherUserIsLogged()) serviceManager -> showIncomes();
    else {
        cout << "You must be logged in to show incomes." << endl;
        system("pause");
    }
}

void Budget::showExpenses(){

    if (userManager.whetherUserIsLogged()) serviceManager -> showExpenses();
    else {
        cout << "You must be logged in to show incomes." << endl;
        system("pause");
    }
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
