#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <conio.h>
#include "UserManager.h"

using namespace std;

class Budget {

    UserManager userManager;

public:

    Budget (string usersFileName)
        : userManager(usersFileName) {
    };

    void userRegistration();
    void showUsers();
    void logging();
    void passwordChange();
    void loggingOut();
    void loginMenu();
    void userMenu();
    bool whetherUserIsLogged();
};

#endif // BUDGET_H
