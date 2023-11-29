#include<iostream>
using namespace std;
int main()
{   
    int N=0,D=0;
    int S_packageA=0,S_packageB=0,A_forcustomer=0,B_forcustomer=0,C_packageA=0,C_packageB;
    cin>>N>>D;
    cin>>S_packageA>>S_packageB;
    int total_customers=0,index=0,total_sum;
    int min_index;
        if(N<=100)
        {
            while(N--)
            {
                cin>>C_packageA>>C_packageB;
                int sum=C_packageA+C_packageB;
                
                if((D-sum)!=0 && (D-sum)>0)
                {
                cout<<"D - sum = "<<D-sum<<endl;
                D=D-C_packageA;
                D=D-C_packageB;
                total_customers++;
                index++;   
                    if(total_sum<sum)
                        {
                            total_sum=sum;
                            // min_index=index;
                        }
                }
                else
                {
                    index++;
                }
            }
        }
        cout<<"Index : "<<index<<endl;
        cout<<"Total customers : "<<total_customers<<endl;
        cout<<"Min index : "<<total_sum<<endl;
}