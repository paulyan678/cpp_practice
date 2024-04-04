#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    cout << "Enter a number of cents: ";
    int cents;
    cin >> cents;
    // int dollar = (int) cents / 100;
    // cents %= 100;
    // int quarters = (int) cents / 25;
    // cents %= 25;
    // int dime = (int) cents / 10;
    // cents %= 10;
    // int nickels = (int) cents / 5;
    // cents %= 5;
    // int penny = (int) cents;
    // cout << "dollars: " << dollar << endl;
    // cout << "quarters: " << quarters << endl;
    // cout << "dimes: " << dime << endl;
    // cout << "nickels: " << nickels << endl;
    // cout << "pennies: " << penny << endl;

    const vector <pair<string, int>> coins {
        {"dollars", 100},
        {"quarters", 25},
        {"dimes", 10},
        {"nickels", 5},
        {"pennies", 1}
    };

    for (auto coin : coins) {
        cout << coin.first << ": " << (int) cents / coin.second << endl;
        cents %= coin.second;
    }
    return 0;
    
}