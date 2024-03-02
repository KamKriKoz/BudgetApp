#include "ServiceManager.h"

void ServiceManager::showSingleResourceDetails(Resources resource) {

    cout << "Date: \t\t\t" << DateMethods::convertDateToStringFormat(resource.date) << endl;
    cout << "Amount: \t\t" << resource.amount << endl;
    cout << "Item: \t\t\t" << resource.item << endl << endl;
}

void ServiceManager::addIncome() {

    system("cls");
    cout << "ADDING NEW INCOME" << endl << endl;

    Resources income = enterNewResourceDetails(INCOME);
    incomes.push_back(income);

    resourcesFile.addToResourcesFile(income, INCOME);

    cout << "Income has been added." << endl;

    system ("pause");
}

void ServiceManager::addExpense() {

    system("cls");
    cout << "ADDING NEW EXPENSE" << endl << endl;

    Resources expense = enterNewResourceDetails(EXPENSE);
    expenses.push_back(expense);

    cout << "Expense has been added." << endl;

    system ("pause");
}

void ServiceManager::showIncomes() {

    system("cls");
    if (!incomes.empty()) {

        for (Resources resource : incomes) showSingleResourceDetails(resource);

    } else cout << "There are no incomes yet." << endl;
    system("pause");
}

void ServiceManager::showExpenses() {

    system("cls");
    if (!expenses.empty()) {

        for (Resources resource : expenses) showSingleResourceDetails(resource);

    } else cout << "There are no expenses yet." << endl;
    system("pause");
}

void ServiceManager::showBalance() {

    system("cls");

    double balance = 0.00;
    double incomesSum = 0.00;
    double expensesSum = 0.00;

    for (Resources resource : incomes) {

        incomesSum += resource.amount;
    }

    for (Resources resource : expenses) {

        expensesSum += resource.amount;
    }

    balance = incomesSum - expensesSum;
    cout << "Balance equals: " << balance << endl;

    system("pause");
}

Resources ServiceManager::enterNewResourceDetails(const Type &type) {

    system("cls");
    double amount = 0.00;
    //int lastResourceId = 0;  //!!! TO REPAIR !!!//
    string item = "";
    SYSTEMTIME time;
    GetSystemTime(&time);
    Resources resource;

    switch (type) {
    case INCOME:
        resource.resourceId = resourcesFile.getNewResourceId(INCOME);

        break;
    case EXPENSE:

        break;
    }

    resource.userId = ID_LOGGED_USER;
    resource.date = DateMethods::getCurrentDateAsInteger(time);

    cout << "Enter name of the item: ";
    item = HelperMethods::loadLine();
    resource.item = item;

    cout << "Enter amount: ";
    amount = HelperMethods::loadDouble();
    resource.amount = amount;

    return resource;
}
