#include <iostream>
using namespace std;

int main() {
    // Declare variables to store user input
    double currentAssets, currentLiabilities, cashAndEquivalents;

    // Get user input for current assets and current liabilities
    cout << "Enter current assets: ";
    cin >> currentAssets;

    cout << "Enter current liabilities: ";
    cin >> currentLiabilities;

    // Get user input for cash and cash equivalents
    cout << "Enter cash and cash equivalents: ";
    cin >> cashAndEquivalents;

    // Calculate the current ratio
    double currentRatio = currentAssets / currentLiabilities;

    // Calculate the cash ratio
    double cashRatio = cashAndEquivalents / currentLiabilities;

    // Display the results
    cout << "Current Ratio: " << currentRatio << endl;
    cout << "Cash Ratio: " << cashRatio << endl;

    return 0;
}
