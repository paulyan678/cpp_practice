#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main() {
    int number_of_small_rooms {0};
    int number_of_large_rooms {0};
    
    /* value of const can not be modified */
    const double price_per_small_room {25.0};
    const double price_per_large_room {35.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; // days

    cout << "Welcome to Frank Cleaning Service" << endl;
    cout << "Enter the number of small rooms you would like cleaned: ";
    cin >> number_of_small_rooms;
    cout << "Enter the number of large rooms you would like cleaned: ";
    cin >> number_of_large_rooms;
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;
    double cost {(price_per_small_room * number_of_small_rooms) + (price_per_large_room * number_of_large_rooms)};
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << cost * sales_tax << endl;
    cout << "Esitmate expiry: " << estimate_expiry << " days" << endl;
    cout << "====================================" << endl;
}