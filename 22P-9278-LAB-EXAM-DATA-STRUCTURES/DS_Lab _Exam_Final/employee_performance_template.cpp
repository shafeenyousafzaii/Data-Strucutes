#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
	int employeeID;
	string name;
	float sales;
	float customerSatisfaction;
	float projectCompletion;
	float performanceScore;

	Employee(int employeeID = 0, string name = "", float customerSatisfaction = 0, float projectCompletion = 0, float sales = 0)
	{
		this->employeeID = employeeID;
		this->name = name;
		this->customerSatisfaction = customerSatisfaction;
		this->projectCompletion = projectCompletion;
		this->sales = sales;
	}

	void calculatePerformanceScore()
	{
		performanceScore = sales + customerSatisfaction + projectCompletion;
	}
	void update(int employeeID, float newSales, float newCS, float newPCE)
	{
		this->employeeID = employeeID;
		this->name = name;
		this->customerSatisfaction = customerSatisfaction;
		this->projectCompletion = projectCompletion;
		this->sales = sales;
	}
};

class MaxHeap
{
public:
	vector<Employee> employeeHeap;

	// int getParent(int child)
	// {
	// }

	int getLeft(int parent)
	{
		int leftchild = 2 * (parent) + 1;
		if (employeeHeap.size() < leftchild)
		{
			return -1;
		}
		else
		{
			return leftchild;
		}
	}

	int getRight(int parent)
	{
		int rightchild = 2 * (parent) + 2;

		if (parent > employeeHeap.size())
		{
			return -1;
		}
		else
		{
			return rightchild;
		}
	}
	void swap(Employee *a, Employee *b)
	{
		Employee temp = *a;
		*a = *b;
		*b = temp;
	}

	void heapifyUp(int node)
	{
		int parent = node;
		int inserted = employeeHeap[employeeHeap.size()].performanceScore;
		if (/*parent <*/ employeeHeap[inserted].performanceScore > parent)
		{
			int temp = employeeHeap[inserted].performanceScore;
			employeeHeap[inserted].performanceScore = employeeHeap[parent].performanceScore;
			employeeHeap[parent].performanceScore = temp;
		}
	}

	void heapifyDown(int node)
	{
		int leftchild = getLeft(node);
		int rightchild = getRight(node);
		int smallest = node;

		if (employeeHeap[node].performanceScore > employeeHeap[smallest].performanceScore)
		{

			smallest = leftchild;
		}
		cout << employeeHeap[node].performanceScore << endl;
		if (employeeHeap[node].performanceScore > employeeHeap[smallest].performanceScore)
		{
			smallest = rightchild;
		}

		if (smallest != node)
		{

			swap(&employeeHeap[node], &employeeHeap[smallest]);
			heapifyDown(smallest);
		}
	}

	void insertEmployee(Employee emp)
	{
		employeeHeap.push_back(emp);
		int index = employeeHeap.size();
		int parent = (index - 1) / 2;
		heapifyUp(parent);
		emp.calculatePerformanceScore();
	}

	void getTopRankingEmployee()
	{
		int score = 0;
		int index=0;
		for (int i = 0; i < employeeHeap.size(); i++)
		{
			if (employeeHeap[i].performanceScore > score)
			{
				if(i==0)
				{
					index=0;
					
				}
				else if(i>0)
				{
					index++;
				}
				score = employeeHeap[i].performanceScore;
			}
		}
		cout<<"Top ranked employee is "<<employeeHeap[index].name<<endl;
	}

	void updatePerformance(int employeeID, float newSales, float newCS, float newPCE)
	{
		for (int i = 0; i < employeeHeap.size(); i++)
		{
			if (employeeHeap[i].employeeID == employeeID)
			{
				employeeHeap[i].update(employeeID, newSales, newCS, newPCE);
				employeeHeap[i].calculatePerformanceScore();
			}
		}
	}

	void displayEmployees()
	{
		if (employeeHeap.empty())
		{
			cout << "No Employees." << endl;
			return;
		}
		cout << "Employee Rankings:" << endl;
		for (const Employee &emp : employeeHeap)
		{
			cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
		}
	}
};

int main()
{
	MaxHeap employeeMaxHeap;

	while (true)
	{
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int id;
			string name;
			float sales, cs, pce;
			cout << "Enter Employee ID: ";
			cin >> id;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Employee Name: ";
			getline(cin, name);
			cout << "Enter Sales (in percentage): ";
			cin >> sales;
			cout << "Enter Customer Satisfaction (in percentage): ";
			cin >> cs;
			cout << "Enter Project Completion Efficiency (in percentage): ";
			cin >> pce;

			Employee newEmployee(id, name, cs, pce, sales);
			newEmployee.calculatePerformanceScore();
			employeeMaxHeap.insertEmployee(newEmployee);
			cout << "Employee added successfully!" << endl;
			break;
		}
		case 2:
		{
			employeeMaxHeap.getTopRankingEmployee();
			break;
		}
		case 3:
		{
			int empID;
			float newSales, newCS, newPCE;
			cout << "Enter Employee ID to update scores: ";
			cin >> empID;
			cout << "Enter new Sales (in percentage): ";
			cin >> newSales;
			cout << "Enter new Customer Satisfaction (in percentage): ";
			cin >> newCS;
			cout << "Enter new Project Completion Efficiency (in percentage): ";
			cin >> newPCE;
			employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
			break;
		}
		case 4:
		{
			employeeMaxHeap.displayEmployees();
			break;
		}
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}
