#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include "restaurant.h"
#include "rms.cpp"

int main() {
    Restaurant restaurant;

    int choice;
    double bill;
    double tipPercentage;
    vector<pair<string, int>> itemsOrdered;

    do {
        cout << "\nRestaurant Management System\n";
        cout << "1. Display Menu\n";
        cout << "2. Add Item to Menu\n";
        cout << "3. Remove Item from Menu\n";
        cout << "4. Place Order\n";
        cout << "5. View Previous Orders\n";
        cout << "6. Calculate Total Amount\n";
        cout << "7. Calculate Total Amount with Tip\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                restaurant.displayMenu();
                break;
            case 2:
                restaurant.addItem();
                break;
            case 3:
                restaurant.removeItem();
                break;
            case 4:
                itemsOrdered.clear();
                bill = restaurant.placeOrder(itemsOrdered);
                restaurant.displayBillBreakup(bill, itemsOrdered);
                break;
            case 5:
                restaurant.displayPreviousOrders();
                break;
            case 6:
                cout << "Total amount of all orders: $" << fixed << setprecision(2) << restaurant.calculateTotalAmount() << endl;
                break;
            case 7:
                cout << "Enter tip percentage: ";
                cin >> tipPercentage;
                cout << "Total amount with tip: $" << fixed << setprecision(2) << restaurant.calculateTotalWithTip(tipPercentage) << endl;
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}