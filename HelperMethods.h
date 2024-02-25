#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

class HelperMethods {

public:

    static string conversionToString(int number);
    static string loadLine();
    static string convertDateToStringFormat(int date);
    static int convertDateToInteger(string date);
    static int conversionToInt(string number);
    static int loadInteger();
    static double loadDouble();
    static int getCurrentDateAsInteger(SYSTEMTIME time);
};

#endif // HELPERMETHODS_H
