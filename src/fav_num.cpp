#include <iostream>

 int main()
 {
    int fav_num;
    int fav_num2;
    // cout is the standard output stream tpically the terminal
    std::cerr << "Enter a number between 1 and 100\n";
    // cin reads from the console
    std::cin >> fav_num >> fav_num2;
    std::cout << "Amazing!! ";
    std::cout << fav_num;
    std::cout << fav_num2;
    std::cout << " is my favorite number too!";
    std::cout << std::endl;
    return 0;
 }