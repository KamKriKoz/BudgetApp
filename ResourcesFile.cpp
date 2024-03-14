#include "ResourcesFile.h"

string ResourcesFile::getIncomesFileName() {

    return RESOURCE_FILE_NAME;
}

string ResourcesFile::getExpensesFileName() {

    return RESOURCE_FILE_NAME;
}

void ResourcesFile::addToResourcesFile(Resources resource, const Type &type) {

    string fileName = "";
    string resourceType = "";

    switch (type) {
    case INCOME:
        fileName = getIncomesFileName();
        resourceType = "Income";
    case EXPENSE:
        fileName = getExpensesFileName();
        resourceType = "Expense";
    }

    if (!xml.Load(fileName)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(fileName);
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(resourceType);
    xml.IntoElem();
    xml.AddElem("Id",resource.resourceId);
    xml.AddElem("UserId", resource.userId);
    xml.AddElem("Date", resource.date);
    xml.AddElem("Item", resource.item);
    xml.AddElem("Amount", HelperMethods::conversionDoubleToString(resource.amount));

    xml.Save(fileName);
}

vector <Resources> ResourcesFile::loadIncomesFromFile(int ID_LOGGED_USER) {

    Resources income;
    vector <Resources> incomes;

    if (!xml.Load(getIncomesFileName())) {
        system ("cls");
        cout << "There are no incomes yet. Incomes file has been created." << endl;
        system("pause");
    } else {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do {
            xml.IntoElem();

            xml.FindElem();
            income.resourceId = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.userId = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.date = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.item = xml.GetData();

            xml.FindElem();
            income.amount = std::stod((xml.GetData().c_str()));

            if (income.userId == ID_LOGGED_USER) incomes.push_back(income);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return incomes;
}

vector <Resources> ResourcesFile::loadExpensesFromFile(int ID_LOGGED_USER) {

    Resources expense;
    vector <Resources> expenses;

    if (!xml.Load(getExpensesFileName())) {
        system ("cls");
        cout << "There are no expenses yet. Expenses file has been created." << endl;
        system("pause");
    } else {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do {
            xml.IntoElem();

            xml.FindElem();
            expense.resourceId = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.userId = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.date = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.item = xml.GetData();

            xml.FindElem();
            expense.amount = std::stod((xml.GetData().c_str()));

            if (expense.userId == ID_LOGGED_USER) expenses.push_back(expense);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return expenses;
}

int ResourcesFile::getNewResourceId(const Type &type) {

    int lastResourceId = 1;
    string fileName = "";

    switch (type) {
    case INCOME:
        fileName = getIncomesFileName();
    case EXPENSE:
        fileName = getExpensesFileName();
        break;
    }

    if (!xml.Load(fileName)) {
        return lastResourceId;
    } else {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do {
            xml.IntoElem();
            xml.FindElem();
            lastResourceId = atoi(xml.GetData().c_str());
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.OutOfElem();
        } while (xml.FindElem());

        return lastResourceId + 1;
    }
}
