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

    ResourcesFile(string resourcesFileName) {};
    void addToResourcesFile(Resources resource, const Type &type);
    vector <Resources> loadResourcesFromFile();
    int getNewResourceId(const Type &type);
};

#endif // RESOURCESFILE_H
