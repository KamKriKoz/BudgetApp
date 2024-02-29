#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include "HelperMethods.h"

using namespace std;

class DateMethods {

public:

    static string convertDateToStringFormat(int date);
    static int convertDateToInteger(string date);
    static int getCurrentDateAsInteger(SYSTEMTIME time);
};

#endif // DATEMETHODS_H
