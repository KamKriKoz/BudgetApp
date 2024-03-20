#include "ServiceManager.h"

void ServiceManager::showSingleResourceDetails(Resources resource) {

    std::cout.precision(2);
    std::cout << std::fixed;

    cout << "Date: \t\t\t" << DateMethods::convertDateToStringFormat(resource.date) << endl;
    cout << "Amount: \t\t" << resource.amount << endl;
    cout << "Item: \t\t\t" << resource.item << endl << endl;
}

void ServiceManager::addIncome() {

    system("cls");
    cout << "ADDING NEW INCOME" << endl << endl;

    Resources income = enterNewResourceDetails(INCOME);
    incomes.push_back(income);

    incomesFile.addToResourcesFile(income, INCOME);

    cout << "Income has been added." << endl;

    system ("pause");
}

void ServiceManager::addExpense() {

    system("cls");
    cout << "ADDING NEW EXPENSE" << endl << endl;

    Resources expense = enterNewResourceDetails(EXPENSE);
    expenses.push_back(expense);

    expensesFile.addToResourcesFile(expense, EXPENSE);

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

void ServiceManager::showCurrentMonthBalance() {

    showBalance(DateMethods::getCurrentMonthFirstDate(), DateMethods::getCurrentDateAsInteger());
}

void ServiceManager::showPreviousMonthBalance() {

    showBalance(DateMethods::getPreviousMonthFirstDate(), DateMethods::getPreviousMonthLastDate());
}

void ServiceManager::showCustomPeriodBalance() {

    system("cls");
    string startDate, endDate = "";

    cout << "Enter start date in format yyyy-mm-dd: ";
    startDate = HelperMethods::loadLine();

    cout << "Enter end date in format yyyy-mm-dd: ";
    endDate = HelperMethods::loadLine();

    showBalance(DateMethods::convertDateToInteger(startDate), DateMethods::convertDateToInteger(endDate));
}

void ServiceManager::showBalance(int startDate, int endDate) {

    system("cls");
    double balance = 0.00;
    std::cout.precision(2);
    std::cout << std::fixed;

    balance = calculateResources(startDate, endDate, INCOME) - calculateResources(startDate, endDate, EXPENSE);

    cout << "The balance is: " << balance << endl << endl;
    system ("pause");
}

double ServiceManager::calculateResources(int startDate, int endDate, const Type &type) {

    double resourceSum = 0.00;

    switch (type) {
    case INCOME:
        for (size_t i = 0; i < incomes.size(); i++) {
            if ((incomes[i].date >= startDate) && (incomes[i].date <= endDate)) {
                resourceSum += incomes[i].amount;
            }
        }
        break;

    case EXPENSE:
        for (size_t i = 0; i < expenses.size(); i++) {
            if ((expenses[i].date >= startDate) && (expenses[i].date <= endDate)) {
                resourceSum += expenses[i].amount;
            }
        }
        break;
    }

    return resourceSum;
}

Resources ServiceManager::enterNewResourceDetails(const Type &type) {

    system("cls");
    string item, amount = "";
    Resources resource;

    switch (type) {
    case INCOME:
        resource.resourceId = incomesFile.getNewResourceId(INCOME);
        break;
    case EXPENSE:
        resource.resourceId = expensesFile.getNewResourceId(EXPENSE);
        break;
    }

    resource.userId = ID_LOGGED_USER;
    resource.date = DateMethods::getCurrentDateAsInteger();

    cout << "Enter name of the item: ";
    item = HelperMethods::loadLine();
    resource.item = item;

    cout << "Enter amount: ";
    amount = HelperMethods::loadLine();
    resource.amount = std::stod(amount);

    return resource;
}
