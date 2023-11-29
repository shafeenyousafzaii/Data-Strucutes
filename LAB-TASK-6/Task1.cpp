#include<iostream>
#include<string>
#include"Array_based_list.h"
using namespace std;
int main()
{
    list l1(9);
    l1.insert(5,1);
    l1.insert(2,2);
    l1.insert(9,3);
    l1.insert(4,4);
    l1.insert(7,5);
    l1.insert(6,6);
    l1.insert(1,7);
    l1.insert(3,8);
    l1.insert(8,9);
    l1.print();
    l1.rearrangeList();
    l1.print();
       
}