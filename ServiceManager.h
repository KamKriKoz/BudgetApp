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
#include "Type.h"
#include "HelperMethods.h"
#include "DateMethods.h"
#include "ResourcesFile.h"

using namespace std;

class ServiceManager {

    const int ID_LOGGED_USER;

    ResourcesFile resourcesFile;

    vector <Resources> incomes;
    vector <Resources> expenses;

    Resources enterNewResourceDetails(const Type &type, string incomesFileName);
    void showSingleResourceDetails(Resources resource);

public:

    ServiceManager(int idLoggedUser, string incomesFileName) : ID_LOGGED_USER(idLoggedUser), resourcesFile(incomesFileName) {
        incomes = resourcesFile.loadResourcesFromFile(ID_LOGGED_USER, incomesFileName);
    };
    void addIncome(string incomesFileName);
    void addExpense();
    void showIncomes();
    void showExpenses();
    void showBalance();
};

#endif // SERVICEMANAGER_H
