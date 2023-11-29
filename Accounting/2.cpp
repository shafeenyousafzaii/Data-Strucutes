#include <iostream>
using namespace std;

int main() {
    // Declare variables to store user input
    //LIQUIDITY RATIOS

    double revenueYearN, revenueYearNMinus1, currentAssets, currentLiabilities, inventory, cashAndEquivalents;

    // Get user input
    cout << "Enter the revenue for Year N: ";
    cin >> revenueYearN;

    cout << "Enter the revenue for Year N-1: ";
    cin >> revenueYearNMinus1;

    cout << "Enter current assets: ";
    cin >> currentAssets;

    cout << "Enter current liabilities: ";
    cin >> currentLiabilities;

    cout << "Enter inventory: ";
    cin >> inventory;

    cout << "Enter cash and cash equivalents: ";
    cin >> cashAndEquivalents;

    // Calculate the percentage change in revenue year on year
    double percentageChangeInRevenue = ((revenueYearN - revenueYearNMinus1) / revenueYearNMinus1) * 100;

    // Calculate the current ratio
    double currentRatio = currentAssets / currentLiabilities;

    // Calculate the quick ratio (acid-test ratio)
    double quickRatio = (currentAssets - inventory) / currentLiabilities;

    // Calculate the cash ratio
    double cashRatio = cashAndEquivalents / currentLiabilities;

    // Display the results
    cout << "Percentage Change in Revenue Year on Year: " << percentageChangeInRevenue << "%" << endl;
    cout << "Current Ratio: " << currentRatio << endl;
    cout << "Quick Ratio (Acid-Test Ratio): " << quickRatio << endl;
    cout << "Cash Ratio: " << cashRatio << endl;

    return 0;
}
