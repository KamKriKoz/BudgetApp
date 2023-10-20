#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

class HelperMethods {
    SYSTEMTIME time;

public:

    static string conversionToString(int number);
    static string loadLine();
    static string covertDateToStringFormat(int date);
    static int conversionToInt(string number);
    static int loadInteger();
    int getCurrentDateAsInteger();
};

#endif // HELPERMETHODS_H
