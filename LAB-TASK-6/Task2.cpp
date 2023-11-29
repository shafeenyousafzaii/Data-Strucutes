#include <iostream>
#include <string>
#include "circular_single_list.h"
using namespace std;
int main()
{
    Cir_list c1;
    c1.insert('m', 1);
    c1.insert('a', 2);
    c1.insert('d', 3);
    c1.insert('a', 4);
    c1.insert('m', 5);
    c1.display();
    bool ans = c1.isPalindrome();
    if (ans == true)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }
    return 1;
}