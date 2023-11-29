#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate random profitability ratios
    double grossProfitMargin = (rand() % 1901 + 100) / 100.0;
    double netProfitMargin = (rand() % 1101 + 500) / 100.0;
    double roa = (rand() % 901 + 200) / 100.0;

    // Generate random liquidity ratios
    double currentRatio = (rand() % 1301 + 1200) / 100.0;
    double quickRatio = (rand() % 680 + 120) / 100.0;
    double cashRatio = (rand() % 61 + 20) / 100.0;

    // Display the generated ratios
    cout << "Gadoon Textile Financial Ratios (Randomly Generated)" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Gross Profit Margin: " << grossProfitMargin << "%" << endl;
    cout << "Net Profit Margin: " << netProfitMargin << "%" << endl;
    cout << "Return on Assets (ROA): " << roa << "%" << endl;
    cout << "Current Ratio: " << currentRatio << endl;
    cout << "Quick Ratio (Acid-Test Ratio): " << quickRatio << endl;
    cout << "Cash Ratio: " << cashRatio << endl;

    return 0;
}
