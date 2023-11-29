#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int threshold;
        cin >> threshold; // Threshold for the current test case

        int n; // Number of packets received in the current test case
        cin >> n;

        vector<int> xi(n); // List of packet counts

        for (int i = 0; i < n; i++) {
            cin >> xi[i]; // Read the list of packet counts
        }

        // Calculate the second-order difference Δ2i and check against the threshold θ
        for (int i = 2; i < n; i++) {
            int secondOrderDiff = abs(xi[i] - 2 * xi[i - 1] + xi[i - 2]);

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
