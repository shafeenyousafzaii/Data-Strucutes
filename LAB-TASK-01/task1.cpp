#include<iostream>
using namespace std;
void swapping_numbers(int *ptr1,int *ptr2);
int main()
{
    int *ptr1;
    int number;
    ptr1 = &number;
    int *ptr2;
    int number2;
    ptr2 = &number2;
    cout<<"Enter two numbers to swap them "<<endl;
    cin>>*ptr1>>*ptr2;
    cout<<"Before swapping: "<<*ptr1<<" "<<*ptr2<<endl;
    swapping_numbers(ptr1,ptr2);
    cout<<"After swapping: "<<*ptr1<<" "<<*ptr2<<endl;

}
void swapping_numbers(int *ptr1 , int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2= temp;

}