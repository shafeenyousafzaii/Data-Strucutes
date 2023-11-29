#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    int threshold;
    cin >> threshold;
    int ans[t][t];
    int check=t;
    while (t--)
    {

        int n; // Number of packets per second
        cin >> n;

        vector<int> packets(n);
        for (int i = 0; i < n; i++)
        {
            cin >> packets[i];
        }

        for (int i = 2; i < n; i++)
        {
            int secondOrderDiff = abs(packets[i] - 2 * packets[i - 1] + packets[i - 2]);
            if (secondOrderDiff >= threshold)
            {
                ans[check-t+1][i]=1;
            }
            else
            {
                ans[check-t+1][i]=0;
            }
        }

        // cout << endl;
    }
    for(int i=0;i<check;i++)
    {
        for(int j=0;j<check;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        }

return 0;                
}
    
    

