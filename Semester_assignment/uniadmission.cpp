#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>
using namespace std;

vector<vector<map<string, int>>> queues;

void printMenu() {
  cout << "1. Add Student to Queue" << endl;
  cout << "2. Process Admissions" << endl; 
  cout << "3. Check Queue Status" << endl;
  cout << "4. See who is next" << endl;
  cout << "5. Exit" << endl;
}

void addStudent() {
  string name;
  int merit;
  
  cout << "Enter student name: "; 
  cin >> name;

  cout << "Enter merit score: ";
  cin >> merit;

  int shortest = 0;

  for(int i=0; i<queues.size(); i++) {
    if(queues[i].size() < queues[shortest].size()) {
      shortest = i;
    }
  }

  queues[shortest].push_back({{"name", name}, {"merit", merit}});

  cout << "Student " << name << " added to queue " << shortest+1 << endl;
}

void processAdmissions() {
  for(int i=0; i<queues.size(); i++) {
    if(!queues[i].empty()) {
      map<string, int> student = queues[i][0];
      queues[i].erase(queues[i].begin());

      if(student["merit"] > 50) {
        cout << "Student " << student["name"] << " admitted!" << endl;  
      }
      else {
        cout << "Student " << student["name"] << " not admitted." << endl;
      }
    }
  }

  cout << "Admissions processing complete" << endl;
}

void checkStatus() {
  for(int i=0; i<queues.size(); i++) {
    cout << "Queue " << i+1 << ": " << queues[i].size() << " students" << endl;

    for(auto student: queues[i]) {
      cout << " - " << student["name"] << endl;
    }
  }
}

void seeNext() {
  int queueNum;

  cout << "Enter queue number: ";
  cin >> queueNum;
  queueNum--;

  if(!queues[queueNum].empty()) {
    cout << "Next in queue " << queueNum+1 << " is " << queues[queueNum][0]["name"] << endl;
  }
  else {
    cout << "Queue is empty." << endl; 
  }
}

int main() {
  queues = {{},{},{}};

  int choice;

  do {
    printMenu();
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
      case 1: 
        addStudent();
        break;

      case 2:
        processAdmissions(); 
        break;

      case 3: 
        checkStatus();
        break;

      case 4:
        seeNext();
        break;

      case 5:
        break;

      default:
        cout << "Invalid choice" << endl;
    }

  } while(choice != 5);

  return 0;
}