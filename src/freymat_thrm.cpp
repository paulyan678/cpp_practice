#include <iostream>
#include <random>
#include <limits>

int main() {
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(1, std::numeric_limits<int>::max()); // Define the range

    int randomInt = distr(eng); // Generate a random integer within the range
    std::cout << "Random positive integer: " << randomInt << std::endl;

    return 0;
}