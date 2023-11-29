#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int countUniqueCombinations(vector<vector<int>>& employees, int person, set<int>& selectedDepartments, int n) {
    if (person == n) {
        return 1;
    }

    int combinations = 0;

    for (int department : employees[person]) {
        if (selectedDepartments.find(department) == selectedDepartments.end()) {
            selectedDepartments.insert(department);
            combinations += countUniqueCombinations(employees, person + 1, selectedDepartments, n);
            selectedDepartments.erase(department);
        }
    }

    return combinations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> employees(n);

      
        for (int i = 0; i < n; i++) {
            int numDepartments;
            cin >> numDepartments;

            for (int j = 0; j < numDepartments; j++) {
                int department;
                cin >> department;
                employees[i].push_back(department);
            }
        }

        set<int> selectedDepartments;
        int combinations = countUniqueCombinations(employees, 0, selectedDepartments, n);

        cout << combinations << endl;
    }

    return 0;
}
