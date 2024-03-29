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
    static string conversionDoubleToString(double number);
    static string loadLine();
    static int conversionToInt(string number);
    static int loadInteger();
};

#endif // HELPERMETHODS_H
