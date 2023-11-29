#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_PEOPLE = 10;
const int MAX_DEPARTMENTS = 100;

int countUniqueCombinations(int departments[MAX_DEPARTMENTS][MAX_PEOPLE], int numPeople, int currentIndex, unordered_map<int, int>& departmentCounts) {
    if (currentIndex == numPeople) {
        return 1;  // A valid unique combination is found
    }

    int totalCombinations = 0;

    for (int i = 0; i < numPeople; i++) {
        int department = departments[currentIndex][i];
        if (departmentCounts[department] > 0) {
            departmentCounts[department]--;
            totalCombinations += countUniqueCombinations(departments, numPeople, currentIndex + 1, departmentCounts);
            departmentCounts[department]++;
        }
    }

    return totalCombinations;
}

int main() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int numPeople, numDepartments;
        cin >> numPeople >> numDepartments;

        int departments[MAX_DEPARTMENTS][MAX_PEOPLE] = {0};
        unordered_map<int, int> departmentCounts;

        for (int i = 0; i < numPeople; i++) {
            int numPersonDepartments;
            cin >> numPersonDepartments;

            for (int j = 0; j < numPersonDepartments; j++) {
                int department;
                cin >> department;
                departments[i][j] = department;
                departmentCounts[department]++;
            }
        }

        int totalCombinations = countUniqueCombinations(departments, numPeople, 0, departmentCounts);
        cout << totalCombinations << endl;
    }

    return 0;
}