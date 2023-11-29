#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // Add some elements to the vector
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i);
    }

    // Print the size and capacity of the vector
    std::cout << "Size: " << myVector.size() << std::endl;
    std::cout << "Capacity: " << myVector.capacity() << std::endl;

    return 0;
}
