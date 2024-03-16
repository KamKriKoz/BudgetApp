#pragma once

#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Resources.h"
#include "Type.h"
#include "HelperMethods.h"
#include "DateMethods.h"
#include "ResourcesFile.h"

using namespace std;

class ServiceManager {

    const int ID_LOGGED_USER;

    ResourcesFile incomesFile;
    ResourcesFile expensesFile;

    vector <Resources> incomes;
    vector <Resources> expenses;

    Resources enterNewResourceDetails(const Type &type);
    void showSingleResourceDetails(Resources resource);

public:

    ServiceManager(int idLoggedUser, string incomesFileName, string expensesFileName) : ID_LOGGED_USER(idLoggedUser), incomesFile(incomesFileName), expensesFile(expensesFileName) {
        incomes = incomesFile.loadIncomesFromFile(ID_LOGGED_USER);
        expenses = expensesFile.loadExpensesFromFile(ID_LOGGED_USER);
    };
    void addIncome();
    void addExpense();
    void showIncomes();
    void showExpenses();
    void showBalance();
};

#endif // SERVICEMANAGER_H
