#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int t; 
    cin >> t;
    int threshold;
    cin >> threshold;

    vector<vector<int>> results; 

    while (t--) {
        int n;
        cin >> n;

        vector<int> packets(n);
        for (int i = 0; i < n; i++) {
            cin >> packets[i];
        }

        vector<int> testCaseResult; 

        for (int i = 2; i < n; i++) {
            int secondOrderDiff = abs(packets[i] - 2 * packets[i - 1] + packets[i - 2]);
            if (secondOrderDiff >= threshold) {
                testCaseResult.push_back(1);
            } else {
                testCaseResult.push_back(0);
            }
        }

        results.push_back(testCaseResult); 
    }

    for (const vector<int>& result : results) {
        for (int value : result) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
