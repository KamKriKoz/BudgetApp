#include "Resources.h"

void Resources::setId(int newResourceId) {
    if (newResourceId >= 0) resourceId = newResourceId;
}

void Resources::setAmount(int newAmount) {
    amount = newAmount;
}

void Resources::setDate(int newDate) {
    date = newDate;
}

void Resources::setItem(string newItem) {
    item = newItem;
}

int Resources::getId() {
    return resourceId;
}

int Resources::getAmount() {
    return amount;
}

int Resources::getDate() {
    return date;
}

string Resources::getItem() {
    return item;
}
