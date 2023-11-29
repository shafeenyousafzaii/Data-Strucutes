#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> storagee(n);

    for (int i = 0; i < n; i++) {
        cin >> storagee[i];
    }

    long long steps = 0;
    int prev = storagee[0];  

    for (int i = 1; i < n; i++) {
        if (storagee[i] < prev) {
            steps += prev - storagee[i]; 
        } else {
            prev = storagee[i]; 
        }
    }

    cout << steps << endl;

    return 0;
}
