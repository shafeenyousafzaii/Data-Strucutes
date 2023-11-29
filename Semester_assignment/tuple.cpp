#include <iostream>
#include <tuple>

int main() {
    // Create a tuple
    std::tuple<int, double, std::string> myTuple = std::make_tuple(42, 3.14, "Hello");

    // Modify the second element (double)
    double newDoubleValue = 2.718;
    auto modifiedTuple = std::make_tuple(std::get<0>(myTuple), newDoubleValue, std::get<2>(myTuple));

    // Access the modified values
    int intVal = std::get<0>(modifiedTuple);
    double doubleVal = std::get<1>(modifiedTuple);
    std::string strVal = std::get<2>(modifiedTuple);

    std::cout << "Modified Tuple: " << intVal << ", " << doubleVal << ", " << strVal << std::endl;

    return 0;
}
