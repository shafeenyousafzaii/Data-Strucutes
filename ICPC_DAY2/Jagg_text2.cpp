#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int* calculateJRP(int** graph, int N) {
    int* JRP = new int[N];
    for (int i = 0; i < N; i++) {
        JRP[i] = 0;
    }

    for (int k = 0; k < N; k++) {
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && i != k && j != k) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                        #pragma omp atomic
                        JRP[i]++;
                        #pragma omp atomic
                        JRP[j]++;
                    }
                }
            }
        }
    }

    return JRP;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        int N, M;
        cin >> N >> M;
        int** graph = new int*[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new int[N];
            for (int j = 0; j < N; j++) {
                graph[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            int U, V;
            cin >> U >> V;
            U--; 
            V--;
            graph[U][V] = graph[V][U] = 1;
        }

        int* JRP = calculateJRP(graph, N);

        int* crossingsWithJRP = new int[N];
        for (int i = 0; i < N; i++) {
            crossingsWithJRP[i] = i + 1;  
        }

        for (int i = 0; i < min(5, N); i++) {
            cout << crossingsWithJRP[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < N; i++) {
            delete[] graph[i];
        }
        delete[] graph;
        delete[] JRP;
        delete[] crossingsWithJRP;
    }

    return 0;
}
