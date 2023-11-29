#include <iostream>
#include <queue>

void reverseOddPositions(std::queue<int>& myQueue) {
    std::queue<int> tempQueue; // Temporary queue to store reversed elements at odd positions

    // Iterate through the original queue
    int size = myQueue.size();
    for (int i = 1; i <= size; ++i) {
        int currentElement = myQueue.front();
        myQueue.pop();

        // Reverse elements at odd positions
        if (i % 2 != 0) {
            tempQueue.push(currentElement);
        } else {
            myQueue.push(currentElement);
        }
    }

    // Reconstruct the original queue with reversed elements at odd positions
    while (!tempQueue.empty()) {
        myQueue.push(tempQueue.front());
        tempQueue.pop();
    }
}

int main() {
    std::queue<int> myQueue;

    // Populate the queue with some elements
    for (int i = 1; i <= 6; ++i) {
        myQueue.push(i);
    }

    std::cout << "Original Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    std::cout << "\n";

    // Restore the queue
    for (int i = 1; i <= 6; ++i) {
        myQueue.push(i);
    }

    // Reverse odd positions
    reverseOddPositions(myQueue);

    std::cout << "Queue with Reversed Odd Positions: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
