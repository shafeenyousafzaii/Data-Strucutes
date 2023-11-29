#include <iostream>
#include <queue>
using namespace std;
void reverseOddPositions(queue<int>& inputQueue) {
    queue<int> oddPositions, evenPositions;

    int queueSize = inputQueue.size();
    
    for (int i = 0; i < queueSize; ++i) {
        int currentElement = inputQueue.front();
        inputQueue.pop();

        if (i % 2 == 0) {
            evenPositions.push(currentElement);
        } else {
            oddPositions.push(currentElement);
        }
    }
    while (!evenPositions.empty()) {
        inputQueue.push(evenPositions.front());
        evenPositions.pop();
    }

    while (!oddPositions.empty()) {
        inputQueue.push(oddPositions.back());
        oddPositions.pop();
    }
}

int main() {
    queue<int> myQueue;

    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
    }

    cout << "Original Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
    }

    reverseOddPositions(myQueue);

    cout << "\nModified Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
