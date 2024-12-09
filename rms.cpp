#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include "restaurant.h"

using namespace std;
    Restaurant::Restaurant() {
        menu = {
            {"Burger", 5.99},
            {"Pizza", 8.99},
            {"Salad", 4.99},
            {"Pasta", 7.99}
        };
    }

    void Restaurant::displayMenu() const {
        cout << "Menu:\n";
        cout << setw(20) << left << "Name" << setw(10) << right << "Price" << endl;
        cout << string(30, '-') << endl;
        for (const auto& item : menu) 
        {
            cout << setw(20) << left << item.name << setw(10) << right << item.price << endl;
        }
    }

    void Restaurant::addItem() {
        MenuItem newItem;
        cout << "Enter name of the item: ";
        cin >> newItem.name;
        cout << "Enter price of the item: ";
        cin >> newItem.price;
        menu.push_back(newItem);
        cout << "Item added to the menu.\n";
    }

    void Restaurant::removeItem() {
        string itemName;
        cout << "Enter name of the item to remove: ";
        cin >> itemName;
        for (auto it = menu.begin(); it != menu.end(); ++it) 
        {
            if (it->name == itemName) 
            {
                menu.erase(it);
                cout << "Item removed from the menu.\n";
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }

    double Restaurant::placeOrder(vector<pair<string, int>>& itemsOrdered) {
        string itemName;
        int quantity;
        double total = 0;
        int numPeople = 0;
        cout << "Enter item name and quantity (enter 'done' to finish): \n";
        while (true) 
        {
            cout << "Item name: ";
            cin >> itemName;
            if (itemName == "done") 
            {
                break;
            }
            cout << "Quantity: ";
            cin >> quantity;
            for (const auto& item : menu) 
            {
                if (item.name == itemName) 
                {
                    total += item.price * quantity;
                    itemsOrdered.push_back(make_pair(itemName, quantity));
                    numPeople += quantity;
                    break;
                }
            }
        }
        if (numPeople > 5) 
        {
            total += total * 0.18;
        }
        double tax = total * 0.05;
        total += tax;
        return total;
    }

    void Restaurant::displayBillBreakup(double total, const vector<pair<string, int>>& itemsOrdered) const {
        cout << "Bill Breakup:\n";
        cout << setw(20) << left << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << string(50, '-') << endl;
        for (const auto& item : itemsOrdered) 
        {
            double itemPrice = 0;
            for (const auto& menuItem : menu) 
            {
                if (menuItem.name == item.first) 
                {
                    itemPrice = menuItem.price;
                    break;
                }
            }
            double itemTotal = itemPrice * item.second;
            cout << setw(20) << left << item.first << setw(10) << item.second << setw(10) << itemPrice << setw(10) << itemTotal << endl;
        }
        double tax = total * 0.05;
        cout << setw(40) << right << "Tax (5%): $" << setw(10) << fixed << setprecision(2) << tax << endl;
        if (itemsOrdered.size() > 5) 
        {
            double gratuity = total * 0.18;
            cout << setw(40) << right << "Gratuity (18%): $" << setw(10) << fixed << setprecision(2) << gratuity << endl;
        }
        cout << setw(40) << right << "Total: $" << setw(10) << fixed << setprecision(2) << total << endl;
    }

    double Restaurant::calculateTotalAmount() const {
        double total = 0;
        for (const auto& order : orders) 
        {
            total += order.totalPrice;
        }
        return total;
    }

    void Restaurant::generateReceipt(const Order& order) const {
        cout << "Receipt for Order at " << ctime(&order.timestamp);
        cout << "Item Name: " << order.itemName << endl;
        cout << "Quantity: " << order.quantity << endl;
        cout << "Total Price: $" << order.totalPrice << endl;
    }

    void Restaurant::displayPreviousOrders() const {
        cout << "Previous Orders:\n";
        for (const auto& order : orders) 
        {
            generateReceipt(order);
            cout << endl;
        }
    }

    double Restaurant::calculateTotalWithTip(double tipPercentage) const {
        double totalAmount = calculateTotalAmount();
        double tipAmount = totalAmount * (tipPercentage / 100.0);
        return totalAmount + tipAmount;
    }

// int main() 
// {
//     Restaurant restaurant;

//     int choice;
//     double bill;
//     double tipPercentage;
//     vector<pair<string, int>> itemsOrdered;

//     do 
//     {
//         cout << "\nRestaurant Management System\n";
//         cout << "1. Display Menu\n";
//         cout << "2. Add Item to Menu\n";
//         cout << "3. Remove Item from Menu\n";
//         cout << "4. Place Order\n";
//         cout << "5. View Previous Orders\n";
//         cout << "6. Calculate Total Amount\n";
//         cout << "7. Calculate Total Amount with Tip\n";
//         cout << "8. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) 
//         {
//             case 1:
//                 restaurant.displayMenu();
//                 break;
//             case 2:
//                 restaurant.addItem();
//                 break;
//             case 3:
//                 restaurant.removeItem();
//                 break;
//             case 4:
//                 itemsOrdered.clear();
//                 bill = restaurant.placeOrder(itemsOrdered);
//                 restaurant.displayBillBreakup(bill, itemsOrdered);
//                 break;
//             case 5:
//                 restaurant.displayPreviousOrders();
//                 break;
//             case 6:
//                 cout << "Total amount of all orders: $" << fixed << setprecision(2) << restaurant.calculateTotalAmount() << endl;
//                 break;
//             case 7:
//                 cout << "Enter tip percentage: ";
//                 cin >> tipPercentage;
//                 cout << "Total amount with tip: $" << fixed << setprecision(2) << restaurant.calculateTotalWithTip(tipPercentage) << endl;
//                 break;
//             case 8:
//                 cout << "Exiting program.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 8);

//     return 0;
// }