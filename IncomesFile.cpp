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
    xml.AddElem("IncomeId",income.getResourceId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", HelperMethods::convertDateToStringFormat(income.getDate()));
    xml.AddElem("Amount", income.getAmount());
    xml.AddElem("Item", income.getItem());

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
            income.setResourceId(atoi(xml.GetData().c_str()));

            xml.FindElem();
            income.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem();
            income.setDate(HelperMethods::convertDateToInteger(xml.GetData()));

            xml.FindElem();
            income.setAmount(atoi(xml.GetData().c_str()));

            xml.FindElem();
            income.setItem(xml.GetData());

            incomes.push_back(income);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return incomes;
}
