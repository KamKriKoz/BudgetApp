#include "UsersFile.h"

void UsersFile::addToUsersFile(User person, string fileName) {

    if (!xml.Load(fileName)) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", person.getId());
    xml.AddElem("Login", person.getLogin());
    xml.AddElem("Password", person.getPassword());
    xml.AddElem("Name", person.getName());
    xml.AddElem("Surname", person.getSurname());

    xml.Save(fileName);
}

vector <User> UsersFile::loadUsersFromFile(string fileName) {

    User person;
    vector <User> users;

    if (!xml.Load(fileName)) {
        cout << "There are no users yet." << endl;
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
            person.setId(atoi(xml.GetData().c_str()));

            xml.FindElem();
            person.setLogin(xml.GetData());

            xml.FindElem();
            person.setPassword(xml.GetData());

            xml.FindElem();
            person.setName(xml.GetData());

            xml.FindElem();
            person.setSurname(xml.GetData());

            users.push_back(person);

            xml.OutOfElem();

        } while (xml.FindElem());
    }
    return users;
}

void UsersFile::overwriteUsersFile(vector <User> &users, string fileName) {

    xml.ResetPos();
    xml.IntoElem();
    xml.FindElem();
    xml.RemoveElem();
    xml.AddElem("Users");

    for (size_t i = 0; i < users.size(); i++) {

        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", users[i].getId());
        xml.AddElem("Login", users[i].getLogin());
        xml.AddElem("Password", users[i].getPassword());
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());

        xml.Save(fileName);
    }
}
