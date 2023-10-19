#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelperMethods.h"
#include "Markup.h"

using namespace std;

class UsersFile {

public:

    UsersFile(string fileName) {};
    void addToUsersFile(User person);
    vector <User> loadUsersFromFile();
    void overwriteUsersFile(vector <User> &users);
};

#endif // USERFILE_H
