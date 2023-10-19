#include "UsersFile.h"
/*
void UsersFile::addToUsersFile(User person) {

    string lineWithData;
    fstream file;
    file.open(getFileName().c_str(), ios::app);

    if (file.good()) {
        lineWithData = transformatingToFormat(person);
        if (whetherFileIsEmpty()) file << lineWithData;
        else file << endl << lineWithData;
        file.close();
    }
    else cout << "File " << getFileName() << " failed to open." << endl;
}
*/
vector <User> UsersFile::loadUsersFromFile() {

    // CREATING XML FILE IF DOESN'T EXIST //
    CMarkup xml;
    bool ifExist = true;
    User person;
    vector <User> users;
    int lastPersonId = 0;

    if (!xml.Load("Users.xml")) {
        ifExist = false;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.Save("Users.xml");

        cout << "File has been created." << endl;
        system("pause");
        system("cls");
    }

    // LOADING TO VECTOR FROM FILE (IF EXIST)//
    else {
        xml.ResetPos();
        xml.IntoElem(); // Users
        xml.FindElem();
        xml.IntoElem(); // User
        xml.FindElem();

        do {
            xml.IntoElem(); // UserId / Login / Password / Name / Surname

            xml.FindElem(); //UserId
            person.setId(atoi(xml.GetData().c_str()));
            lastPersonId = (atoi(xml.GetData().c_str()));

            xml.FindElem(); //Login
            person.setLogin(xml.GetData());

            xml.FindElem(); //Password
            person.setPassword(xml.GetData());

            xml.FindElem(); //Name
            person.setName(xml.GetData());

            xml.FindElem(); //Surname
            person.setSurname(xml.GetData());

            users.push_back(person);

            xml.OutOfElem();

        } while (xml.FindElem());
    }

    return users;
}
/*
void UsersFile::overwriteUsersFile(vector <User> &users) {

    ofstream file;
    file.open(getFileName());

    file << users[0].getId() << "|";
    file << users[0].getLogin() << "|";
    file << users[0].getPassword() << "|";

    for (size_t i = 1; i < users.size(); i++) {

        file << endl;
        file << users[i].getId() << "|";
        file << users[i].getLogin() << "|";
        file << users[i].getPassword() << "|";
    }

    file.close();
}
*//*
string UsersFile::transformatingToFormat(User person) {

    string lineWithData = "";
    lineWithData.append(HelperMethods::conversionToString(person.getId()));
    lineWithData.push_back('|');
    lineWithData.append(person.getLogin());
    lineWithData.push_back('|');
    lineWithData.append(person.getPassword());
    lineWithData.push_back('|');

    return lineWithData;
}
*//*
User UsersFile::downloadOneUserData(string oneUserData) {

    User person;
    string singleData = "";
    int numberOfSingleData = 1;

    for (size_t position = 0; position < oneUserData.length(); position++) {
        if (oneUserData[position] != '|') singleData += oneUserData[position];
        else {
            switch (numberOfSingleData) {
            case 1:
                person.setId(atoi(singleData.c_str()));
                break;
            case 2:
                person.setLogin(singleData);
                break;
            case 3:
                person.setPassword(singleData);
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }
    return person;
}
*/
