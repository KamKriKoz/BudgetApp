#include "Resources.h"

void Resources::setUserId(int newUserId) {
    if (newUserId >= 0) userId = newUserId;
}

void Resources::setResourceId(int newResourceId) {
    if (newResourceId >= 0) resourceId = newResourceId;
}

void Resources::setDate(int newDate) {
    date = newDate;
}

void Resources::setAmount(int newAmount) {
    amount = newAmount;
}

void Resources::setItem(string newItem) {
    item = newItem;
}

int Resources::getUserId() {
    return userId;
}

int Resources::getResourceId() {
    return resourceId;
}

int Resources::getDate() {
    return date;
}

int Resources::getAmount() {
    return amount;
}

string Resources::getItem() {
    return item;
}
