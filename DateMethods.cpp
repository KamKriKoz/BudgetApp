#include "DateMethods.h"

SYSTEMTIME DateMethods::getCurrentTime() {

    SYSTEMTIME time;
    GetSystemTime(&time);

    return time;
}

string DateMethods::convertDateToStringFormat(int date) {

    string dateInFormat = HelperMethods::conversionToString(date);
    dateInFormat.insert(4, "-");
    dateInFormat.insert(7, "-");

    return dateInFormat;
}

int DateMethods::convertDateToInteger(string date) {

    int dateInFormat = 0;
    date.erase(5,1);
    date.erase(7,1);
    dateInFormat = HelperMethods::conversionToInt(date);

    return dateInFormat;
}

int DateMethods::getCurrentDateAsInteger() {

    string dateAsString = "";
    SYSTEMTIME time = getCurrentTime();

    dateAsString = HelperMethods::conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wMonth)) : dateAsString.append(HelperMethods::conversionToString(time.wMonth));
    (time.wDay < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wDay)) : dateAsString.append(HelperMethods::conversionToString(time.wDay));

    return HelperMethods::conversionToInt(dateAsString);
}

int DateMethods::getCurrentMonthFirstDate() {

    SYSTEMTIME time = getCurrentTime();
    string dateAsString = "";

    dateAsString = HelperMethods::conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wMonth)) : dateAsString.append(HelperMethods::conversionToString(time.wMonth));
    dateAsString.append("01");

    return HelperMethods::conversionToInt(dateAsString);
}

int DateMethods::getPreviousMonthFirstDate() {

    SYSTEMTIME time = getCurrentTime();
    string dateAsString = "";

    if (time.wMonth == 1) {
        time.wYear = time.wYear - 1;
        time.wMonth = 12;
    } else {
        time.wMonth = time.wMonth - 1;
    }

    dateAsString = HelperMethods::conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wMonth)) : dateAsString.append(HelperMethods::conversionToString(time.wMonth));
    dateAsString.append("01");

    return HelperMethods::conversionToInt(dateAsString);
}

int DateMethods::getPreviousMonthLastDate() {

    SYSTEMTIME time = getCurrentTime();
    string dateAsString = "";

    if (time.wMonth == 1) {
        time.wYear = time.wYear - 1;
        time.wMonth = 12;
    } else {
        time.wMonth = time.wMonth - 1;
    }

    time.wDay = howManyDaysInMonth(time);

    dateAsString = HelperMethods::conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wMonth)) : dateAsString.append(HelperMethods::conversionToString(time.wMonth));
    (time.wDay < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wDay)) : dateAsString.append(HelperMethods::conversionToString(time.wDay));

    return HelperMethods::conversionToInt(dateAsString);
}

int DateMethods::howManyDaysInMonth(SYSTEMTIME time) {

    int numberOfDays = 0;

    switch(time.wMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays = 30;
        break;

    case 2: {
        if(((time.wYear %4 == 0) && (time.wYear %100 != 0)) || (time.wYear %400 == 0)) numberOfDays = 29;
        else numberOfDays = 28;
        break;
    }
    }

    return numberOfDays;
}
