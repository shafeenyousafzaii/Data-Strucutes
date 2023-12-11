#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph {
	int n=5; // Number of nodes in the graph
    bool matrix[n][n];// take  2D static array of fixed size for ease 
    
public:
    graph(int size) {
    	// initialize all the values of the matrix to false
    }

    void addedge(int source, int destination, bool bi) {
    	// here bool bi means bidirectional or not
    	// if true so node 1 should be connected to node 2 and also the vice versa
       
    }

    void removeEdge(int source, int destination, bool bi) {
        
    }

    void DFS(int start) {
    	// here you can use the built-in stack from stack library.
        
    }

    void BFS(int start) {
    	// here you can use the built-in queue from the queue library
        
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
   // simple make a graph containing 5 nodes, connect some edges yourself
   // call the print, dfs, and bfs function
    return 0;
}
