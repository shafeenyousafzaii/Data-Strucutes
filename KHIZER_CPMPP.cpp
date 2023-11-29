// #include <iostream>
// #include <cmath>
// #include <limits>
// using namespace std;

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         double alpha;
//         cin >> alpha;

//         double min_value = numeric_limits<double>::max();
//         int result = 0;
//         for (int n = 1; n <= 360; n++) {
//             double value = abs(cos(n * M_PI / 180.0 * alpha));
//             if (value < min_value) {
//                 min_value = value;
//                 result = n;
//             }
//             if(min_value==0)
//             {
//                 break;
//             }
//         }

//         cout << result << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double alpha = 88.81784197001252323389053344765625;  // Replace with your desired value of alpha
    int n = 90;

    double result = cos(n * alpha )* (M_PI / 180.0);
    cout << result << endl;

    return 0;
}
