#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    // Method to append a node at the end of the linked list
    void append(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method to reverse a group of k nodes starting from the given node
    ListNode* reverseKNodes(ListNode* startNode, int k) {
        ListNode* prev = nullptr;
        ListNode* current = startNode;
        ListNode* nextNode = nullptr;
        int count = 0;

        // Count the number of nodes in this group
        while (current != nullptr && count < k) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        // If there are more nodes in the list, recursively reverse the next group
        if (nextNode != nullptr) {
            startNode->next = reverseKNodes(nextNode, k);
        }

        return prev; // Return the new head of this group
    }

    // Method to reverse every alternate group of k nodes
    void reverseAlternateKNodes(int k) {
        head = reverseKNodes(head, k);
    }

    // Method to display the linked list
    void display() {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList llist;
    for (int i = 1; i <= 15; i++) {
        llist.append(i);
    }

    int k = 3;
    
    std::cout << "Original linked list:" << std::endl;
    llist.display();

    llist.reverseAlternateKNodes(k);

    std::cout << "after reversing "<< std::endl;
    llist.display();

    return 0;
}
