#include <iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class Node {
	public:
		int val;
		Node* next;
		Node(int val) {
			this->val = val;
			next = NULL;
		}
};

class LinkedList {
	public:
		Node* head;
		LinkedList() {
			head = NULL;
		}

		void append(int val) {
			Node* newNode = new Node(val);
			if (head == NULL) {
				head = newNode;
			} else {
				Node* curr = head;
				while (curr->next != NULL) {
					curr = curr->next;
				}
				curr->next = newNode;
			}
		}
		void remove(int val) {
			Node* curr = head;
			Node* prev = NULL;

			// If the head node itself needs to be removed
			if (curr != NULL && curr->val == val) {
				head = curr->next; // Change head
				delete curr;        // Free old head
				return;
			}

			// Search for the node to be removed, keep track of the previous node
			while (curr != NULL && curr->val != val) {
				prev = curr;
				curr = curr->next;
			}

			// If the node was not found
			if (curr == NULL) return;

			// Unlink the node from the list
			prev->next = curr->next;

			// Free memory
			delete curr;
		}
		void printList() {
			Node* curr = head;
			while (curr != NULL) {
				cout << curr->val << " ";
				curr = curr->next;
			}
		}
};

class graph {
		LinkedList* adjlist; // pointer to an array of linked list
		int n;
	public:
		graph(int size) {
			adjlist = new LinkedList[size]; // initialize the pointer to point to a dynamic aray of linked list
			n = size;
		}

		void addedge(int source, int destination, bool bi) {
		
		}

		void removeEdge(int source, int destination, bool bi) {
		
		}

		void DFS(int start) {
			// you can use the built-in stack and vector to use in this method
		}
		void BFS(int start) {
			// you can use the built-in queue and vector to use in this method
		
		}

		void print() {
			// print the adjacency list
		}
};

int main() {
	graph g(5);
	g.addedge(0, 1, true);
	g.addedge(3, 1, true);
	g.addedge(0, 2, true);
	g.addedge(3, 2, true);
	g.addedge(0, 3, true);

	cout << "Graph before removing edges:" << endl;
	g.print();
	
	cout << "Graph after removing edges:" << endl;
	g.removeEdge(3, 1, true);
	g.print();
		
	g.DFS(1);
	cout<<"\nBFS: \n";
	g.BFS(1);


}
