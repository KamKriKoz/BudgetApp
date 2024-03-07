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

    const string FILE_NAME;
    CMarkup xml;

public:

    UsersFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    void addToUsersFile(User person);
    vector <User> loadUsersFromFile();
    void overwriteUsersFile(vector <User> &users);
};

#endif // USERFILE_H
