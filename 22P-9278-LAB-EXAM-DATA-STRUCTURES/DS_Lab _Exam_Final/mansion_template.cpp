#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	string data;
	Node *next;
	Node(string val)
	{
		this->data = val;
		next = NULL;
	}
};
class Stack
{
public:
	Node *top;
	int length;
	Stack()
	{
		top = NULL;
		length = 0;
	}
	~Stack()
	{
		Node *curr = NULL;
		while (top != NULL)
		{
			curr = top;
			top = top->next;
			delete curr;
		}
	}

	void push(string val)
	{
		Node *n = new Node(val);
		n->next = top;
		top = n;
		length++;
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
			cout << "Stack is empty" << endl;
		}
		else
		{
			return false;
		}
	}
	string pop()
	{
		if (top == NULL)
		{
			cout << "Stack underflow" << endl;
			return "";
		}
		Node *curr = top;
		string val = curr->data;
		top = top->next;
		delete curr;
		length--;
		return val;
	}

};

class Queue
{
	int front;
	int rear;
	int capacity;
	int length;
	string *arr;

public:
	Queue(int size)
	{
		capacity = size;
		arr = new string[size];
		front = 0;
		rear = -1;
	}
	bool isEmpty()
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (length == capacity - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void EnQueue(string val)
	{
		if (length == capacity)
		{
			cout << "Queue overflow" << endl;
		}
		if (rear == (capacity - 1))
		{
			rear = 0;
		}
		else
		{
			rear++;
		}

		arr[rear] = val;
		length++;
	}
	string Deque()
	{
		if (length == 0)
		{
			cout << "Underflow\n";
		}
		string val = arr[front];
		if (front == (capacity - 1))
		{
			front = 0;
		}
		else
		{
			front++;
		}
		length--;
		return val;
	}

	~Queue()
	{
		delete[] arr;
	}
};
void encountered(Stack &encounters, string name_mansion)
{
	string name;
	cout << "What did you see?" << endl;
	cin.ignore();
	getline(cin, name);
	// cout << name << endl;
	encounters.push(name_mansion);
	encounters.push(name);
}
void Noencounter(Stack &encounters)
{
}
int main()
{
	int choice;
	// Set up the stack for encounters
	Stack encounters;

	Queue mansionQueue(6);
	mansionQueue.EnQueue("The Gateway to Darkness");
	mansionQueue.EnQueue("The Creeping Corridor");
	mansionQueue.EnQueue("The Abandoned Lounge");
	mansionQueue.EnQueue("The Haunted Gallery");
	mansionQueue.EnQueue("The Shadowed Library");
	mansionQueue.EnQueue("The Broken Window");
	cout << "Start exploring the mansion? " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> choice;
	while (choice == 1)
	{
		int choice2;
		string name_mansion;
		name_mansion = mansionQueue.Deque();
		cout << "Currently at : " << name_mansion << endl;
		cout << "Did you encountered a ghost or an evil spirit" << endl;
		cout << "Yes" << endl;
		cout << "No " << endl;
		cin >> choice2;
		if (choice2 == 1)
		{
			encountered(encounters, name_mansion);
			if (name_mansion == "The Broken Window")
			{
				cout << "Yayyy, you escaped safe and sound!" << endl;
				cout << "Most recent ghosts/evil spirits encounters" << endl;
				for (int i = 0; i < encounters.length; i++)
				{
					string man_name = encounters.pop();
					string ghost_name = encounters.pop();
					cout << man_name << " at : " << ghost_name << endl;
				}
				break;
			}
		}
		else if (choice2 == 2)
		{
			if (name_mansion == "The Broken Window")
			{
				cout << "Yayyy, you escaped safe and sound!" << endl;
				cout << "Most recent ghosts/evil spirits encounters" << endl;
				for (int i = 0; i < encounters.length; i++)
				{
					string man_name = encounters.pop();
					string ghost_name = encounters.pop();
					cout << man_name << " at : " << ghost_name << endl;
				}
				break;
			}
			continue;
		}
	}
	if (choice != 1)
	{
		cout << "You chose not to explore the mansion" << endl;
	}
}
