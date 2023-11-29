#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        double alpha;
        cin >> alpha;
        double min_value = numeric_limits<double>::max();
        int result = 0;

        for (int n = 1; n < 1000000; ++n) {  // The upper limit is arbitrary; adjust as needed
            double value = abs(cos((M_PI / 180.0 * n * alpha)));
            if (value < min_value) {
                min_value = value;
                result = n;
            }
            if (min_value == 0) {
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}