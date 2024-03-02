#include "ResourcesFile.h"

void ResourcesFile::addToResourcesFile(Resources resource, const Type &type) {

    if (!xml.Load("Incomes.xml")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",resource.resourceId);
    xml.AddElem("UserId", resource.userId);
    xml.AddElem("Date", resource.date);
    xml.AddElem("Item", resource.item);
    xml.AddElem("Amount", resource.amount);

    xml.Save("Incomes.xml");
}

vector <Resources> ResourcesFile::loadResourcesFromFile() {

    Resources income;
    vector <Resources> incomes;

    if (!xml.Load("Incomes.xml")) {
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

            incomes.push_back(income);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return incomes;
}

int ResourcesFile::getNewResourceId(const Type &type) {

    int lastResourceId = 1;
    string incomesFileName = "";

    switch (type) {
    case INCOME:
        incomesFileName = "Incomes.xml";
    case EXPENSE:

        break;
    }

    if (!xml.Load(incomesFileName)) {
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
