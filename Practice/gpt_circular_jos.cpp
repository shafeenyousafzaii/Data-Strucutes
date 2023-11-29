#include <iostream>

class Node {
public:
    Node* next;
    int data;
    
    Node(int data = 0) {
        this->data = data;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;
    int length;

    CircularLinkedList() {
        head = nullptr;
        length = 0;
    }

    void insert(int val, int pos) {
        Node* n = new Node(val);
        Node* curr = head;

        if (pos < 1 || pos > length + 1) {
            std::cout << "Invalid Position" << std::endl;
            return;
        }

        if (head == nullptr) {
            head = n;
            head->next = head;
        }
        else if (pos == 1) {
            n->next = head;
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = n;
            head = n;
        }
        else {
            for (int i = 1; i < pos - 1; i++) {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        length++;
    }

    void remove(int pos) {
        if (length == 0) {
            std::cout << "Empty" << std::endl;
            return;
        }

        Node* curr = head;
        Node* tail = head;

        if (pos == 1) {
            while (tail->next != head) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;

            if (head == head->next) {
                head = nullptr;
            }

            delete curr;
        }
        else {
            tail = nullptr;
            for (int i = 1; i < pos; i++) {
                tail = curr;
                curr = curr->next;
            }
            tail->next = curr->next;
            delete curr;
        }

        length--;
    }

    void print_all() {
        if (length == 0) {
            std::cout << "Empty List" << std::endl;
            return;
        }

        Node* curr = head;
        do {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != head);

        std::cout << "END" << std::endl;
    }

    void Josephus_problem(int n, int m) {
        for (int i = 1; i <= n; i++) {
            insert(i, i);
        }

        Node* curr = head;
        Node* slow = nullptr;

        while (length != 1) {
            
            int count = 0;
            for (int i = 1; i <= m; i++) {
                slow = curr;
                curr = curr->next;
                count++;
            }
            // slow->next = curr->next;
            int val = curr->data;
            int pos = find(val);
            curr=curr->next;
            remove(pos);
        
        }

        std::cout << "Final value: " << curr->data << std::endl;
    }

    int find(int val) {
        if (head == nullptr) {
            std::cout << "Empty List" << std::endl;
            return -1;
        }

        Node* curr = head;
        for (int i = 1; i <= length; i++) {
            if (curr->data == val) {
                return i;
            }
            curr = curr->next;
        }

        return -1;
    }
};

int main() {
    CircularLinkedList l1;
    // l1.Josephus_problem(5, 3);
    // l1.Josephus_problem(5, 2);
    // l1.Josephus_problem(5, 2);
    // l1.Josephus_problem(4, 3);
    //    l1.Josephus_problem(1,1);
       l1.Josephus_problem(2,4);
    
    return 0;
}
