#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        double a, y, z, va, vy, vz;
        int dur;
        
        cin >> a >> y >> z;
        cin >> va >> vy >> vz;
        cin >> dur;

        for (int t = 0; t < dur; t++) {
            if (a <= 0 || a >= 1000) {
                va = -va;
            }
            if (y <= 0 || y >= 1000) {
                vy = -vy;
            }
            if (z <= 0 || z >= 1000) {
                vz = -vz;
            }
            a += va;
            y += vy;
            z += vz;
        }
        cout << fixed << setprecision(2) << "(" << a << ", " << y << ", " << z << ")" << endl;
    }

    return 0;
}
