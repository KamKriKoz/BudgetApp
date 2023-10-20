#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>

using namespace std;

class Resources {
    int resourceId;
    int amount;
    int date;
    string item;

public:
    void setId(int newResourceId);
    void setAmount(int newAmount);
    void setDate(int newDate);
    void setItem(string newItem);

    int getId();
    int getAmount();
    int getDate();
    string getItem();
};

#endif // RESOURCES_H
