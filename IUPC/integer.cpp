#include <iostream>
#include <cmath>

int main() {
    double number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    // Check if the number is not an integer
    if (std::abs(number - std::round(number)) > 0.00001) {
        std::cout << "The number is not an integer." << std::endl;
    } else {
        std::cout << "The number is an integer." << std::endl;
    }

    return 0;
}
