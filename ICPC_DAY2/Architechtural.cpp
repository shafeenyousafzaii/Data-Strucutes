#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &ways, int node, int parent) {
    int ways_with_node = 1;
    int ways_without_node = 0;

    for (int child : adj[node]) {
        if (child == parent) continue;
        int ways_child = dfs(adj, ways, child, node);
        ways_with_node *= (1 + ways_child);
        ways_without_node *= (ways_with_node + ways_without_node);
    }

    ways[node] = ways_with_node;
    return ways_with_node;
}

int possible_ways_to_build_plaza(int n, vector<vector<int>> &connections) {
    vector<vector<int>> adj(n);
    for (auto connection : connections) {
        int u = connection[0];
        int v = connection[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ways(n, 0);
    dfs(adj, ways, 0, -1);

    return ways[0];
}

int main() {
    int t; // Number of test cases
    cin >> t;

    vector<pair<int, vector<vector<int>>>> inputs;
    vector<int> results;

    while (t--) {
        int n; // Number of shops
        cin >> n;
        vector<vector<int>> connections(n - 1, vector<int>(2));
        for (int i = 0; i < n - 1; i++) {
            cin >> connections[i][0] >> connections[i][1];
        }
        inputs.emplace_back(n, connections);

        int result = possible_ways_to_build_plaza(n, connections);
        results.push_back(result);
    }

    // Print results
    for (int res : results) {
        cout << (res > 0 ? to_string(res) : "-1") << endl;
    }

    return 0;
}