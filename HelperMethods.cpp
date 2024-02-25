#include "HelperMethods.h"

string HelperMethods::conversionToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::loadLine() {

    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string HelperMethods::convertDateToStringFormat(int date) {

    string dateInFormat = conversionToString(date);
    dateInFormat.insert(4, "-");
    dateInFormat.insert(7, "-");

    return dateInFormat;
}

int HelperMethods::convertDateToInteger(string date) {

    int dateInFormat = 0;
    date.erase(5,1);
    date.erase(7,1);
    dateInFormat = conversionToInt(date);

    return dateInFormat;
}

int HelperMethods::conversionToInt(string number) {

    int numInt;
    istringstream iss(number);
    iss >> numInt;
    return numInt;
}

int HelperMethods::loadInteger() {

    string input = "";
    int integer = 0;

    while(1) {

        getline(cin, input);
        stringstream myStream(input);

        if (myStream >> integer) break;
        else cout << "This is not an integer. Enter again." << endl;
    }
    return integer;
}

int HelperMethods::getCurrentDateAsInteger(SYSTEMTIME time) {

    string dateAsString = "";

    dateAsString = conversionToString(time.wYear);
    (time.wMonth < 10) ? dateAsString.append('0' + conversionToString(time.wMonth)) : dateAsString.append(conversionToString(time.wMonth));
    (time.wDay < 10) ? dateAsString.append('0' + conversionToString(time.wDay)) : dateAsString.append(conversionToString(time.wDay));

    return conversionToInt(dateAsString);
}
