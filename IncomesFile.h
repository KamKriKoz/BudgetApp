#pragma once

#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Resources.h"
#include "HelperMethods.h"
#include "Markup.h"

using namespace std;

class IncomesFile {

    CMarkup xml;

public:

    IncomesFile(string incomesFileName) {};
    void addToIncomesFile(Resources income);
    vector <Resources> loadIncomesFromFile();
};

#endif // INCOMESFILE_H
