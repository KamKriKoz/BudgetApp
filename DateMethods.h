#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "HelperMethods.h"

using namespace std;

class DateMethods {

public:

    static SYSTEMTIME getCurrentTime();
    static string convertDateToStringFormat(int date);
    static int convertDateToInteger(string date);
    static int getCurrentDateAsInteger();
    static int getCurrentMonthFirstDate();
    static int getPreviousMonthFirstDate();
    static int getPreviousMonthLastDate();
    static int howManyDaysInMonth(SYSTEMTIME time);
};

#endif // DATEMETHODS_H
