#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add numbers" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    char choice;
    vector <int> numbers;
    while (1) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 'P':
            case 'p':
                if (numbers.size() == 0) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    cout << "[ ";
                    for (auto number : numbers) {
                        cout << number << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            case 'A':
            case 'a':
                int number;
                cout << "Enter a number: ";
                cin >> number;
                numbers.push_back(number);
                cout << number << " added" << endl;
                break;
            case 'M':
            case 'm':
                if (numbers.size() == 0) {
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    int sum = 0;
                    for (auto number : numbers) {
                        sum += number;
                    }
                    cout << "Mean: " << (double) sum / numbers.size() << endl;
                }
                break;
            case 'S':
            case 's':
                if (numbers.size() == 0) {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                } else {
                    int smallest = numbers.at(0);
                    for (auto number : numbers) {
                        if (number < smallest) {
                            smallest = number;
                        }
                    }
                    cout << "The smallest number is " << smallest << endl;
                }
                break;
            case 'L':
            case 'l':
                if (numbers.size() == 0) {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                } else {
                    int largest = numbers.at(0);
                    for (auto number : numbers) {
                        if (number > largest) {
                            largest = number;
                        }
                    }
                    cout << "The largest number is " << largest << endl;
                }
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye" << endl;
                return 0;
            default:
                cout << "Unknown selection, please try again" << endl;
        }

    }
    return 1;
}