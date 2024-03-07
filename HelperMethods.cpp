#include "HelperMethods.h"

string HelperMethods::conversionToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::conversionDoubleToString(double number) {

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



