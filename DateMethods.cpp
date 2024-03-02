#include "DateMethods.h"

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

int DateMethods::getCurrentDateAsInteger(SYSTEMTIME time) {

    string dateAsString = "";

    dateAsString = HelperMethods::conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wMonth)) : dateAsString.append(HelperMethods::conversionToString(time.wMonth));
    (time.wDay < 10) ? dateAsString.append('0' + HelperMethods::conversionToString(time.wDay)) : dateAsString.append(HelperMethods::conversionToString(time.wDay));

    return HelperMethods::conversionToInt(dateAsString);
}
