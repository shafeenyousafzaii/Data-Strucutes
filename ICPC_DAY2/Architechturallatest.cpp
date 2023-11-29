#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int& ways) {
    visited[current] = true;
    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            ways++;
            dfs(graph, visited, neighbor, ways);
        }
    }
}

// Function to calculate the number of possible ways to build the plaza
int possibleWaysToBuildPlaza(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n, vector<int>());
    for (const auto& connection : connections) {
        int shop1 = connection[0];
        int shop2 = connection[1];
        graph[shop1].push_back(shop2);
        graph[shop2].push_back(shop1);
    }

    int ways = 0;
    vector<bool> visited(n, false);
    dfs(graph, visited, 0, ways);
    return ways + 1; // Adding 1 for the initial shop
}

int main() {
    int t; // Number of test cases
    cin >> t;

    vector<int> result;

    // Loop through each test case
    for (size_t i = 0; i < t; i++) {
        int n; // Number of shops
        cin >> n;

        // Vector to store connections
        vector<vector<int>> connections;

        // Input connections for each shop
        for (int j = 0; j < n - 1; j++) {
            int shop1, shop2;
            cin >> shop1 >> shop2;
            connections.push_back({shop1, shop2});
        }

        // Calculate the number of possible ways to build the plaza
        result.push_back(possibleWaysToBuildPlaza(n, connections));
    }

    // Output the result
    for (size_t i = 0; i < result.size(); i++) {
        // Output the result
        if (result[i] == -1) {
            cout << "-1" << endl;
        } else {
            cout << result[i] << endl;
        }
    }

    return 0;
}