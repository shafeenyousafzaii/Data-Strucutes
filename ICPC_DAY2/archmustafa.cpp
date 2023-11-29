#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
int ways = 1;

int dfs(int node, int parent) {
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            ways *= dfs(neighbor, node) + 1;
        }
    }
}

int countWaysToBuildPlaza(int n, std::vector<std::pair<int, int>>& connections) {
    graph.resize(n);

    for (const auto& connection : connections) {
        int u = connection.first;
        int v = connection.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1);  // Start the DFS from shop 0

    return ways;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> connections(n - 1);

        for (int j = 0; j < n - 1; j++) {
            int u, v;
            std::cin >> u >> v;
            connections[j] = {u, v};
        }

        int ways = countWaysToBuildPlaza(n, connections);
        std::cout << (ways > 0 ? ways : -1) << std::endl;
        ways = 1;  // Reset ways for the next test case
    }

    return 0;
}