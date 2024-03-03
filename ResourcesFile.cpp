#include "ResourcesFile.h"

void ResourcesFile::addToResourcesFile(Resources resource, const Type &type, string incomesFileName) {

    string fileName = "";
    string resourceType = "";

    switch (type) {
    case INCOME:
        fileName = incomesFileName;
        resourceType = "Income";
    case EXPENSE:

        break;
    }

    if (!xml.Load(fileName)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
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
    xml.AddElem("Amount", resource.amount);

    xml.Save(fileName);
}

vector <Resources> ResourcesFile::loadResourcesFromFile(int ID_LOGGED_USER, string incomesFileName) {

    Resources income;
    vector <Resources> incomes;

    if (!xml.Load(incomesFileName)) {
        cout << "There are no incomes yet." << endl;
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
            income.amount = atoi(xml.GetData().c_str());

            if (income.userId == ID_LOGGED_USER) incomes.push_back(income);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return incomes;
}

int ResourcesFile::getNewResourceId(const Type &type, string incomesFileName) {

    int lastResourceId = 1;
    string fileName = "";

    switch (type) {
    case INCOME:
        fileName = incomesFileName;
    case EXPENSE:

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
