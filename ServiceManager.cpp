#include "ServiceManager.h"

void ServiceManager::showSingleResourceDetails(Resources resource) {

    cout << "Date: \t\t\t" << DateMethods::convertDateToStringFormat(resource.date) << endl;
    cout << "Amount: \t\t" << resource.amount << endl;
    cout << "Item: \t\t\t" << resource.item << endl << endl;
}

void ServiceManager::addIncome() {

    system("cls");
    cout << "ADDING NEW INCOME" << endl << endl;

    Resources income = enterNewResourceDetails();
    incomes.push_back(income);

    incomesFile.addToIncomesFile(income);

    cout << "Income has been added." << endl;

    system ("pause");
}

void ServiceManager::addExpense() {

    system("cls");
    cout << "ADDING NEW EXPENSE" << endl << endl;

    Resources expense = enterNewResourceDetails();
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

Resources ServiceManager::enterNewResourceDetails() {

    system("cls");
    double amount = 0.00;
    int lastResourceId = 0;  //!!! TO REPAIR !!!//
    string item = "";
    SYSTEMTIME time;
    GetSystemTime(&time);
    Resources resource;

    resource.resourceId = lastResourceId + 1; //!!! TO REPAIR !!!//
    resource.userId = ID_LOGGED_USER;
    resource.date = DateMethods::getCurrentDateAsInteger(time);

    cout << "Enter amount: ";
    amount = HelperMethods::loadDouble();
    resource.amount = amount;

    cout << "Enter name of the item: ";
    item = HelperMethods::loadLine();
    resource.item = item;

    return resource;
}
