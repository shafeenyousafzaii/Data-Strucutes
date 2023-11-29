#include <iostream>
#include <string>
#include "LinkedList2.h"
using namespace std;
int main()
{
    List l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(5,5);
    l1.insert(6,6);
    l1.insert(7,7);
    l1.insert(8,8);
    l1.insert(9,9);
    l1.insert(10,10);
    l1.insert(11,11);
    l1.insert(12,12);
    l1.insert(13,13);
    l1.insert(14,14);
    l1.insert(15,15);
    l1.insert(16,16);
    l1.insert(17,17);
    l1.insert(18,18);          
    l1.display();
    l1.reverseKNode(3);
    l1.display();
}
