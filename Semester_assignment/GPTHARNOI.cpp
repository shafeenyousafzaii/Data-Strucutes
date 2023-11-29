#include <iostream>
#include <cmath>

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peak() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void moveDisks(Stack& src, Stack& dest) {
    int disk1 = src.peak();
    int disk2 = dest.peak();

    if (disk1 == -1) {
        int p = dest.pop();
        src.push(p);
    } else if (disk2 == -1) {
        int p = src.pop();
        dest.push(p);
    } else if (disk1 > disk2) {
        int p = dest.pop();
        src.push(p);
    } else {
        int p = src.pop();
        dest.push(p);
    }
}

void hanoi(Stack& src, Stack& dest, Stack& aux, int val) {
    int vall = pow(2, val) - 1;

    for (int i = 1; i <= vall; i++) {
        if (i % 3 == 1) {
            moveDisks(src, dest);
        } else if (i % 3 == 2) {
            moveDisks(src, aux);
        } else if (i % 3 == 0) {
            moveDisks(aux, dest);
        }
    }
}

void harnoi(int n, Stack& s1, Stack& s2, Stack& s3) {
    Stack *dest;
    Stack *aux;

    if (n % 2 == 0) {
        dest = &s2;
        aux = &s3;
    } else {
        dest = &s3;
        aux = &s2;
    }

    int totalMoves = pow(2, n) - 1;

    for (int i = n; i >= 1; i--) {
        s1.push(i);
    }

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDisks(s1, *dest);
        else if (i % 3 == 2)
            moveDisks(s1, *aux);
        else if (i % 3 == 0)
            moveDisks(*aux, *dest);
    }
}

int main() {
    // Example usage:
    int disks = 3;
    Stack source(disks), auxilary(disks), destination(disks);

    hanoi(source, destination, auxilary, disks);

    // Or using the harnoi function
    Stack s1(disks), s2(disks), s3(disks);
    harnoi(disks, s1, s2, s3);

    return 0;
}
