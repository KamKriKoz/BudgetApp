#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFile {

    CMarkup xml;

public:

    UsersFile(string fileName) {};
    void addToUsersFile(User person, string fileName);
    vector <User> loadUsersFromFile(string fileName);
    void overwriteUsersFile(vector <User> &users, string fileName);
};

#endif // USERFILE_H
