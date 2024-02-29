#pragma once

#ifndef RESOURCESFILE_H
#define RESOURCESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Resources.h"
#include "HelperMethods.h"
#include "Markup.h"
#include "DateMethods.h"

using namespace std;

class ResourcesFile {

    CMarkup xml;

public:

    ResourcesFile(string resourcesFileName) {};
    void addToResourcesFile(Resources resource);
    vector <Resources> loadResourcesFromFile();
};

#endif // RESOURCESFILE_H
