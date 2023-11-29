#include <iostream>
using namespace std;
int main() {
    // Define the financial values
    //FOR PROFITIBILITY RATIONS
    double grossProfit = 0;  // Replace with your actual gross profit
    double revenue = 0;     // Replace with your actual revenue
    double netProfit = 0;    // Replace with your actual net profit
    double totalAssets = 0; // Replace with your actual total assets
    cout<<"Enter gross profit"<<endl;
    cin>>grossProfit;
    cout<<"Enter revenue"<<endl;
    cin>>revenue;
    cout<<"Enter netProfit"<<endl;
    cin>>netProfit;
    cout<<"Enter total Assets"<<endl;
    cin>>totalAssets;
    //Calculate Gross Profit Margin
    double grossProfitMargin = (grossProfit / revenue) * 100;

    // Calculate Net Profit Margin
    double netProfitMargin = (netProfit / revenue) * 100;

    // Calculate Return on Assets (ROA)
    double roa = (netProfit / totalAssets) * 100;

    // Display the results
    cout << "Gross Profit Margin: " << grossProfitMargin << "%" << endl;
    cout << "Net Profit Margin: " << netProfitMargin << "%" << endl;
    cout << "Return on Assets (ROA): " << roa << "%" << endl;

    return 0;
}
