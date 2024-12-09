#include <deepstate/DeepState.hpp>
#include "restaurant.h"

using namespace deepstate;

TEST(Restaurant, AddAndDisplayItem) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Add an item to the menu
  restaurant.addItem();

  // Display the menu
  restaurant.displayMenu();
}

TEST(Restaurant, PlaceOrder) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Generate random items to order
  vector<pair<string, int>> itemsOrdered;
  int numItems = DeepState_UIntInRange(1, 5); // Choose a random number of items to order
  for (int i = 0; i < numItems; ++i) {
    string itemName;
    int itemNameLength = DeepState_UIntInRange(1, 10); // Choose a random length for item name
    for (int j = 0; j < itemNameLength; ++j) {
      itemName += DeepState_Char(); // Generate random characters
    }
    int quantity = DeepState_UIntInRange(1, 5); // Choose a random quantity for each item
    itemsOrdered.push_back(make_pair(itemName, quantity));
  }

  // Place the order
  double total = restaurant.placeOrder(itemsOrdered);

  // Display the bill breakup
  restaurant.displayBillBreakup(total, itemsOrdered);
}

TEST(Restaurant, RemoveItem) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Remove an item from the menu
  restaurant.removeItem();

  // Display the menu after removal
  restaurant.displayMenu();
}

TEST(Restaurant, CalculateTotalAmount) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Calculate the total amount of all previous orders
  double totalAmount = restaurant.calculateTotalAmount();

  LOG(TRACE) << "Total Amount: " << totalAmount;

  // Make an assertion to ensure the total amount is non-negative
  ASSERT_GE(totalAmount, 0.0);
}

TEST(Restaurant, CalculateTotalWithTip) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Generate a random tip percentage
  double tipPercentage = DeepState_DoubleInRange(0.0, 30.0); // Tip percentage range: 0% to 30%

  // Calculate total amount with tip
  double totalWithTip = restaurant.calculateTotalWithTip(tipPercentage);

  LOG(TRACE) << "Total Amount with Tip (" << tipPercentage << "%): " << totalWithTip;

  // Make an assertion to ensure the total amount with tip is non-negative
  ASSERT_GE(totalWithTip, 0.0);
}

TEST(Restaurant, DisplayPreviousOrders) {
  // Create a Restaurant instance
  Restaurant restaurant;

  // Display previous orders
  restaurant.displayPreviousOrders();
}
