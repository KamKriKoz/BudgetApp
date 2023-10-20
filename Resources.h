#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>

using namespace std;

class Resources {
    int userId;
    int resourceId;
    int date;
    int amount;
    string item;

public:
    void setUserId(int newUserId);
    void setResourceId(int newResourceId);
    void setDate(int newDate);
    void setAmount(int newAmount);
    void setItem(string newItem);

    int getUserId();
    int getResourceId();
    int getDate();
    int getAmount();
    string getItem();
};

#endif // RESOURCES_H
