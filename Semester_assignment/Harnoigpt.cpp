#include <iostream>
#include <stack>

// Function to show the movement of disks
void moveDisk(int disk, char fromRod, char toRod)
{
    std::cout << "Move disk " << disk << " from rod " << fromRod << " to rod " << toRod << std::endl;
}

// Function to implement Tower of Hanoi puzzle
void towerOfHanoi(int numDisks, std::stack<int> &source, std::stack<int> &destination, std::stack<int> &auxiliary, char fromRod, char toRod, char auxRod)
{
    if (numDisks == 1)
    {
        int topDisk = source.top();
        source.pop();
        destination.push(topDisk);
        moveDisk(topDisk, fromRod, toRod);
        return;
    }
    towerOfHanoi(numDisks - 1, source, auxiliary, destination, fromRod, auxRod, toRod);
    int topDisk = source.top();
    source.pop();
    destination.push(topDisk);
    moveDisk(topDisk, fromRod, toRod);
    towerOfHanoi(numDisks - 1, auxiliary, destination, source, auxRod, toRod, fromRod);
}

int main()
{
    int numDisks = 3; // Specify the number of disks
    std::stack<int> source, destination, auxiliary;

    // Initialize source rod with disks
    for (int i = numDisks; i >= 1; --i)
    {
        source.push(i);
    }

    // Show the initial configuration
    std::cout << "Initial configuration:" << std::endl;
    // Show the current status of the rods
    std::cout << "Source: ";
    while (!source.empty())
    {
        std::cout << source.top() << " ";
        source.pop();
    }
    std::cout << std::endl;

    std::cout << "Destination: ";
    while (!destination.empty())
    {
        std::cout << destination.top() << " ";
        destination.pop();
    }
    std::cout << std::endl;

    std::cout << "Auxiliary: ";
    while (!auxiliary.empty())
    {
        std::cout << auxiliary.top() << " ";
        auxiliary.pop();
    }
    std::cout << std::endl;

    // Solve Tower of Hanoi
    towerOfHanoi(numDisks, source, destination, auxiliary, 'A', 'C', 'B');

    std::cout << "Total moves: " << (1 << numDisks) - 1 << std::endl; // Number of moves required

    return 0;
}
