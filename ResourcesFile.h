#pragma once

#ifndef RESOURCESFILE_H
#define RESOURCESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Resources.h"
#include "Type.h"
#include "HelperMethods.h"
#include "Markup.h"
#include "DateMethods.h"

using namespace std;

class ResourcesFile {

    CMarkup xml;

public:

    ResourcesFile(string incomesFileName) {};
    void addToResourcesFile(Resources resource, const Type &type, string incomesFileName);
    vector <Resources> loadResourcesFromFile(int ID_LOGGED_USER, string incomesFileName);
    int getNewResourceId(const Type &type, string incomesFileName);
};

#endif // RESOURCESFILE_H
