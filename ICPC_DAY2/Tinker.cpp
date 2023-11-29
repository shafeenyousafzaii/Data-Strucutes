#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, double> conversionFactors = {
    {"meters", 39.3701},
    {"centimeters", 0.393701},
    {"liters", 1.057},
    {"quarts", 1.0},
    // Add more conversion factors as needed
};

bool isValidConversion(const string& fromUnit, const string& toUnit) {
    return conversionFactors.find(fromUnit) != conversionFactors.end() &&
           conversionFactors.find(toUnit) != conversionFactors.end();
}

double performConversion(double value, const string& fromUnit, const string& toUnit) {
    if (!isValidConversion(fromUnit, toUnit)) {
        return -1; // Invalid conversion
    }

    return value * conversionFactors[fromUnit] / conversionFactors[toUnit];
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    cin.ignore(); // Consume newline

    for (int i = 0; i < numTestCases; i++) {
        string question;
        getline(cin, question);

        istringstream iss(question);
        string howMany, fromValue, fromUnit, areIn, toValue, toUnit;
        double value;

        iss >> howMany >> value >> fromUnit >> areIn >> toValue >> toUnit;

        double result = performConversion(value, fromUnit, toUnit);

        cout << fixed << (result >= 0 ? result : -1) << endl;
    }

    return 0;
}