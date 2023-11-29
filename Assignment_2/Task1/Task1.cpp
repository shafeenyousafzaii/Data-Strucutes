#include<iostream>
#include<string>
#include"Stack_LL.h"
using namespace std;
int main()
{
    List l1;
    cout<<l1.Post_fix("6 2 3 + - 3 8 2 / + * 2 ^ 3 +")<<endl;
    // cout<<l1.Post_fix("10 5 +")<<endl;
    // l1.display();
}