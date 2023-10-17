#include "HelperMethods.h"

string HelperMethods::conversionToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelperMethods::conversionToInt(string number) {

    int numInt;
    istringstream iss(number);
    iss >> numInt;
    return numInt;
}

string HelperMethods::getNumber(string text, int position) {
    string number = "";
    while(isdigit(text[position]) == true)
    {
        number += text[position];
        position ++;
    }
    return number;
}

string HelperMethods::loadLine() {

    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
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
