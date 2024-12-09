#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct MenuItem {
    string name;
    double price;
};

struct Order {
    string itemName;
    int quantity;
    double totalPrice;
    time_t timestamp;
};

class Restaurant {
private:
    vector<MenuItem> menu;
    vector<Order> orders;

public:
    Restaurant();
    void displayMenu() const;
    void addItem();
    void removeItem();
    double placeOrder(vector<pair<string, int>>& itemsOrdered);
    void displayBillBreakup(double total, const vector<pair<string, int>>& itemsOrdered) const;
    double calculateTotalAmount() const;
    void generateReceipt(const Order& order) const;
    void displayPreviousOrders() const;
    double calculateTotalWithTip(double tipPercentage) const;
};

#endif // RESTAURANT_H
