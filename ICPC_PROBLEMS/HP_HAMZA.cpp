#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int noC;
    int tStock;
    int sizeA;
    int sizeB;

    int cA,cB;

    vector <int> arr;
    vector <int> index;

    cin>>noC>>tStock;
    cin>>sizeA>>sizeB;

    if( noC <= 100)
    {
        int j=0;
        while(j<noC)
        {
            cin>>cA>>cB;
            

            if(tStock-sizeA*cA-sizeB*cB>=0)
            {
                tStock = tStock-cA*sizeA-cB*sizeB;
                int temp = cA*sizeA+cB*sizeB;

                arr.push_back(temp);
                index.push_back(j);
            }
            j++;
        }

        for(std::vector<int>::size_type i=0;i<arr.size();i++)
        {
            for(std::vector<int>::size_type j=i;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    int check = index[i];
                    index[i] = index[j];
                    index[j] = check;
                }
            }
        }
        cout<<arr.size()<<endl;
        for(std::vector<int>::size_type i=0;i<arr.size();i++)
        {
            cout<<index[i]+1<<" ";
            // if(i+1<arr.size())
            //     cout<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}