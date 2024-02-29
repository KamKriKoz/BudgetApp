#pragma once

#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "Resources.h"
#include "HelperMethods.h"
#include "DateMethods.h"
//#include "ExpensesFile.h"
#include "ResourcesFile.h"

using namespace std;

class ServiceManager {

    const int ID_LOGGED_USER;

//   ExpensesFile expensesFile;
    ResourcesFile resourcesFile;

    vector <Resources> incomes;
    vector <Resources> expenses;

    Resources enterNewResourceDetails();
    void showSingleResourceDetails(Resources resource);

public:

    ServiceManager(string incomesFileName, int idLoggedUser) : ID_LOGGED_USER(idLoggedUser), resourcesFile(incomesFileName) {
        incomes = resourcesFile.loadResourcesFromFile();
    };
    void addIncome();
    void addExpense();
    void showIncomes();
    void showExpenses();
    void showBalance();
};

#endif // SERVICEMANAGER_H
