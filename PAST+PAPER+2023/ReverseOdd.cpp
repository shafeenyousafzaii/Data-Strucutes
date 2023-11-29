#include <iostream>
#include <queue>

void reverseOddPositions(std::queue<int>& myQueue) {
    // Temporary queue to store elements at odd positions
    std::queue<int> tempQueue;

    // Counter to keep track of the position
    int position = 1;

    while (!myQueue.empty()) {
        if (position % 2 != 0) {
            // If the position is odd, enqueue the element in the temporary queue
            tempQueue.push(myQueue.front());
        }

        myQueue.pop();
        position++;
    }

    // Reset the position counter
    position = 1;

    // Enqueue elements back into the original queue in reversed order at odd positions
    while (!tempQueue.empty()) {
        if (position % 2 != 0) {
            myQueue.push(tempQueue.front());
        } else {
            // If the position is even, enqueue the element from the original queue
            myQueue.push(myQueue.front());
            myQueue.pop();
        }

        tempQueue.pop();
        position++;
    }
}

int main() {
    std::queue<int> myQueue;

    // Enqueue some elements for testing
    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
    }

    // Display original queue
    std::cout << "Original Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    // Enqueue elements again for testing
    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
    }

    // Reverse odd positions
    reverseOddPositions(myQueue);

    // Display modified queue
    std::cout << "Modified Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
