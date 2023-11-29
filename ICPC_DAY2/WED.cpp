#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{   
    int T;
    cin >> T;
    

    vector<int> results; // To store the results for each test case

    for (int t = 0; t < T; t++)
    {
        int M, C;
        cin >> M >> C;
        cin.ignore(); // Read the newline character after C.

        vector<vector<int>> garments; // Stores the models and prices for each garment class

        for (int j = 0; j < C; j++)
        {
            int numModels;
            cin >> numModels;
            vector<int> prices(numModels, 0);

            for (int k = 0; k < numModels; k++)
            {
                cin >> prices[k];
            }

            garments.push_back(prices);
        }

        // Initialize a 2D array to store the maximum value for each budget and garment class
        vector<vector<int>> dp(C + 1, vector<int>(M + 1, -1));

        // Base case: No budget is needed to buy from the first garment class
        for (int m = 0; m <= M; m++)
        {
            dp[0][m] = 0;
        }

        // Dynamic programming to calculate the maximum amount spent on each garment class
        for (int j = 1; j <= C; j++)
        {
            for (int m = 0; m <= M; m++)
            {
                for (int k = 0; k < garments[j - 1].size(); k++)
                {
                    if (m >= garments[j - 1][k] && dp[j - 1][m - garments[j - 1][k]] != -1)
                    {
                        dp[j][m] = max(dp[j][m], dp[j - 1][m - garments[j - 1][k]] + garments[j - 1][k]);
                    }
                }
            }
        }

        // Find the maximum amount spent on the last garment class within the budget
        int maxAmountSpent = -1;
        for (int m = 0; m <= M; m++)
        {
            if (dp[C][m] != -1)
            {
                maxAmountSpent = max(maxAmountSpent, dp[C][m]);
            }
        }

        results.push_back(maxAmountSpent); // Store the result for this test case
    }

    // Print the results for all test cases
    for (int t = 0; t < T; t++)
    {
        cout << results[t] << endl;
    }

    return 0;
}