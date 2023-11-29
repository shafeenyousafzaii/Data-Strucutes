// #include <iostream>
// #include <set>

// using namespace std;
// set<int> compassAngles;
// // Function to check if an angle can be constructed using compass bisection
// bool isCompassAngle(int angle) {
//     set<int> compassAngles = {0, 30, 45, 60, 90, 120, 135, 150, 180};
//     return compassAngles.find(angle) != compassAngles.end();
// }

// // Function to count the compass angles within the given range
// int countCompassAngles(int start, int end) {
//     int count = 0;
//     for (int angle = start; angle <= end; angle++) {
//         if (compassAngles.find(angle) != compassAngles.end()) {
//             count++;
//         } else {
//             int mid1 = (angle + start) / 2;
//             int mid2 = (angle + end) / 2;
//             count += countCompassAngles(start, mid1) + countCompassAngles(mid1 + 1, mid2) + countCompassAngles(mid2 + 1, end);
//             break; // No need to check other angles in this range
//         }
//     }
//     return count;
// }

// int main() {
//     int start, end;
//     cin >> start >> end;

//     int result = countCompassAngles(start, end);
//     cout << result << endl;

//     return 0;
// }
// #include <iostream>
// #include <set>

// using namespace std;

// // Function to check if an angle can be constructed using compass bisection
// bool isCompassAngle(int angle) {
//     set<int> compassAngles = {0, 30, 45, 60, 90, 120, 135, 150, 180};
//     return compassAngles.find(angle) != compassAngles.end();
// }

// // Function to count the compass angles within the given range
// int countCompassAngles(int start, int end) {
//     int count = 0;
//     for (int angle = start; angle <= end; angle++) {
//         if (isCompassAngle(angle)) {
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     int start, end;
//     cin >> start >> end;

//     int result = countCompassAngles(start, end);
//     cout << result << endl;

//     return 0;
// }
// #include <iostream>
// bool is_compass_angle(int angle) {
//     // Check if the angle can be drawn using a compass
//     if (angle <= 180) {
//         return true;
//     }
//     if (angle % 2 == 0) {
//         return is_compass_angle(angle / 2);
//     }
//     return false;
// }

// int count_compass_angles(int start, int end) {
//     int count = 0;
//     for (int angle = start; angle <= end; angle++) {
//         if (is_compass_angle(angle)) {
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     // Read input
//     int start, end;
//     std::cin >> start >> end;
    
//     // Calculate and print the number of compass angles
//     std::cout << count_compass_angles(start, end) << std::endl;
    
//     return 0;
// }
#include <iostream>

bool is_compass_angle(int angle) {
    return (angle % 2 == 0) || (angle % 3 == 0) || (angle % 5 == 0);
}

int count_compass_angles(int start, int end) {
    int count = 0;
    for (int angle = start; angle <= end; angle++) {
        if (is_compass_angle(angle)) {
            count++;
        }
    }
    return count;
}

int main() {
    // Read input
    int start, end;
    std::cin >> start >> end;
    
    // Calculate and print the number of compass angles
    std::cout << count_compass_angles(start, end) << std::endl;
    
    return 0;
}