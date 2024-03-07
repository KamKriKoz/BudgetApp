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
    const string INCOMES_FILE_NAME;

public:

    Budget (string usersFileName, string incomesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName) {
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
