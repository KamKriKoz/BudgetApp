#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <conio.h>
#include "UserManager.h"
#include "ServiceManager.h"

using namespace std;

class Budget {

    UserManager userManager;
    ServiceManager *serviceManager;

public:

    Budget (string usersFileName)
        : userManager(usersFileName) {
        serviceManager = NULL;
    };

    ~Budget() {
        delete serviceManager;
        serviceManager = NULL;
    }

        void userRegistration();
        void showUsers();
        void logging();
        void passwordChange();
        void loggingOut();
        void loginMenu();
        void userMenu();
        void addIncome();
        void addExpense();
        void showIncomes();
        void showExpenses();
        void showBalance();
        bool whetherUserIsLogged();

        void loadIncomes();
    };

#endif // BUDGET_H
