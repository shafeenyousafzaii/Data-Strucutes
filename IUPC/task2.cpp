#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Point {
    int x, y;
};

int bfs(vector<vector<char>>& island, int n, int m, Point start, Point chest) {
    vector<vector<int>> cost(n, vector<int>(m, INF));
    vector<vector<int>> damage(n, vector<int>(m, INF));

    queue<Point> q;
    q.push(start);
    cost[start.x][start.y] = 0;
    damage[start.x][start.y] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && island[newX][newY] != 'X') {
                int newCost = cost[current.x][current.y] + (island[newX][newY] == 'C' ? 1 : 0);
                int newDamage = damage[current.x][current.y] + 1;
                
                if (newCost < cost[newX][newY] || (newCost == cost[newX][newY] && newDamage < damage[newX][newY])) {
                    cost[newX][newY] = newCost;
                    damage[newX][newY] = newDamage;
                    q.push({newX, newY});
                }
            }
        }
    }

    return cost[chest.x][chest.y];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> island(n, vector<char>(m));
        Point start, chest;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> island[i][j];
                if (island[i][j] == 'T') {
                    start.x = i;
                    start.y = j;
                } else if (island[i][j] == 'C') {
                    chest.x = i;
                    chest.y = j;
                }
            }
        }

        int result = bfs(island, n, m, start, chest);
        cout << result << endl;
    }

    return 0;
}
