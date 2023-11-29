#include <iostream>
#include <vector>
#include <algorithm>

int minimumDisassemblyCost(std::vector<int>& modules) {
    int n = modules.size();
    int totalCost = 0;

    while (n > 1) {
        // Find the indices of the two smallest modules
        int min1 = std::min_element(modules.begin(), modules.end()) - modules.begin();
        int min2 = (min1 == 0) ? 1 : 0; // Ensure min2 is different from min1

        // Calculate the cost of disassembling and update the total cost
        int disassemblyCost = modules[min1] + modules[min2];
        totalCost += disassemblyCost;

        // Combine the two smallest modules into one and remove the other
        modules[min1] = disassemblyCost;
        modules.erase(modules.begin() + min2);

        n--;
    }

    return totalCost;
}

int main() {
    int numTestCases;
    std::cin >> numTestCases;
    int n;
    std::cin >> n;
    for (int t = 0; t < numTestCases; t++) {
        
        
        std::vector<int> modules(n);

        for (int i = 0; i < n; i++) {
            std::cin >> modules[i];
        }

        int cost = minimumDisassemblyCost(modules);
        std::cout << cost << std::endl;
    }

    return 0;
}