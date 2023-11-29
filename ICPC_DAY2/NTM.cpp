#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; 
    cin >> t;
    int threshold;
        cin >> threshold;
    while (t--) {
    

        int n; 
        cin >> n;

        vector<int> packets(n);
        for (int i = 0; i < n; i++) {
            cin >> packets[i];
        }

        for (int i = 2; i < n; i++) {
            int secondOrderDiff = abs(packets[i] - 2 * packets[i - 1] + packets[i - 2]);
            if (secondOrderDiff >= threshold) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }

        cout << endl;
    }

    return 0;
}