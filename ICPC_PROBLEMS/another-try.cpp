#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0, D = 0;
    int S_packageA = 0, S_packageB = 0;
    cin >> N >> D;
    cin >> S_packageA >> S_packageB;
    int total_customers = 0, total_sum = 0;

    for (int i = 0; i < N; i++) {
        int C_packageA, C_packageB;
        cin >> C_packageA >> C_packageB;
        int sum = C_packageA + C_packageB;

        if (D >= sum) {
            D -= sum;
            total_customers++;
            if (sum > total_sum) {
                total_sum = sum;
            }
        }
    }

    cout << "Total customers: " << total_customers << endl;
    // cout << "Max total package size: " << total_sum << endl;

    int noC;
    int tStock;
    int sizeA;
    int sizeB;
    vector<int> arr;
    vector<int> index;

    cin >> noC >> tStock;
    cin >> sizeA >> sizeB;

    for (int j = 0; j < noC; j++) {
        int cA, cB;
        cin >> cA >> cB;

        if (tStock >= cA * sizeA + cB * sizeB) {
            tStock -= cA * sizeA + cB * sizeB;
            int temp = cA * sizeA + cB * sizeB;
            arr.push_back(temp);
            index.push_back(j);
        }
    }

    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                swap(index[i], index[j]);
            }
        }
    }

    cout << arr.size() << endl;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << index[i] + 1;
        if (i + 1 < arr.size()) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
