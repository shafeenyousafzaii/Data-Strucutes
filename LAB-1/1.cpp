#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    cout<<"Enter 5 elements: ";
    int *ptr=arr;

    for(int i = 0 ; i < 5 ; i++ )
    {
        cin>>*ptr;
        ptr ++;
    }
    ptr = arr;
    for(int i = 0 ; i < 5 ; i++)
    {
        cout<<*ptr;
        ptr ++;
    }
     
}