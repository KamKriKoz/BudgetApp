#include "IncomesFile.h"

void IncomesFile::addToIncomesFile(Resources income) {

    if (!xml.Load("Incomes.xml")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.resourceId);
    xml.AddElem("UserId", income.userId);
    xml.AddElem("Date", income.date);
    xml.AddElem("Amount", income.amount);
    xml.AddElem("Item", income.item);

    xml.Save("Incomes.xml");
}

vector <Resources> IncomesFile::loadIncomesFromFile() {

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
            income.amount = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.item = xml.GetData();

            incomes.push_back(income);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return incomes;
}
