#include "ServiceManager.h"

void ServiceManager::showSingleResourceDetails(Resources resource) {

    cout << "Date: \t\t\t" << HelperMethods::convertDateToStringFormat(resource.getDate()) << endl;
    cout << "Amount: \t\t" << resource.getAmount() << endl;
    cout << "Item: \t\t\t" << resource.getItem() << endl << endl;
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

    int balance = 0;
    int incomesSum = 0;
    int expensesSum = 0;

    for (Resources resource : incomes) {

        incomesSum += resource.getAmount();
    }

    for (Resources resource : expenses) {

        expensesSum += resource.getAmount();
    }

    balance = incomesSum - expensesSum;
    cout << "Balance equals: " << balance << endl;

    system("pause");
}

Resources ServiceManager::enterNewResourceDetails() {

    system("cls");
    int amount = 0;
    int lastResourceId = 0;  //!!! TO REPAIR !!!//
    string item;
    SYSTEMTIME time;
    GetSystemTime(&time);
    Resources resource;

    resource.setResourceId(lastResourceId + 1); //!!! TO REPAIR !!!//
    resource.setUserId(ID_LOGGED_USER);
    resource.setDate(HelperMethods::getCurrentDateAsInteger(time));

    cout << "Enter amount: ";
    amount = HelperMethods::loadInteger();
    resource.setAmount(amount);

    cout << "Enter name of the item: ";
    item = HelperMethods::loadLine();
    resource.setItem(item);

    return resource;
}
