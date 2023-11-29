#include <iostream>
#include <vector>

using namespace std;

int main()
{
   freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int threshold;
    cin >> threshold;
    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;
        vector<int> xi;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            xi.push_back(a);
        }

        vector<int> result;
        if (n >= 2)
        {

            for (int k = 2; k < n; k++)
            {

                int secondOrderDiff = abs(abs(xi[k] - xi[k - 1]) - abs(xi[k - 1] - xi[k - 2]));
                if (secondOrderDiff >= threshold)
                {
                    result.push_back(1);
                }
                else
                {
                    result.push_back(0);
                }
            }
        }
        // cout << endl;
        for (int l = 0; l < result.size(); l++)
        {
            cout << result[l] << " ";
        }

        result.clear();

        cout << endl;
    }

    return 0;
}