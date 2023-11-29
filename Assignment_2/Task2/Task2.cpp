#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;
int main()
{
    List l1;
    if(l1.checking_brackets("([{<>}])"))
    {
        cout<<"All brackets are in right manner"<<endl;
    }
    else
    {
        cout<<"All brackets are not in right manner"<<endl;
    }
}