#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBestie(int n) {
    string numStr = to_string(n);
    for (int i = 1; i < numStr.length(); i++) {
        if (abs(numStr[i] - numStr[i - 1]) < 2) {
            return false;
        }
    }
    return true;
}

int countBestiesBetween(int n1, int n2) {
    int count = 0;
    for (int num = n1; num <= n2; num++) {
        if (isBestie(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        int result = countBestiesBetween(n1, n2);
        cout << result << endl;
    }

    return 0;
}
