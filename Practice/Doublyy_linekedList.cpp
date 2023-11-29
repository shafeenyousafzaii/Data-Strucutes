#include<iostream>
#include<string>
#include"Dounly_linkedList.h"
using namespace std;
// int main()
// {
//     Dounly_linkedList l1;
//     int choice;
//     cout<<"Welcome to doubly LinkedList"<<endl;
//     while(1)
//     {
//         cout<<"1)Insert value"<<endl;
//         cout<<"2)Remove value"<<endl;
//         cout<<"3)Display"<<endl;
//         cout<<"4) Reverse"<<endl;
//         cin>>choice;
//         if(choice==1)
//         {
//             int number,pos;
//             cout<<"Enter the number you want to insert"<<endl;
//             cin>>number;
//             cout<<"Enter the pos at which you want to insert"<<endl;
//             cin>>pos;
//             l1.insert(number,pos);
//         }
//         else if(choice==2)
//         {
//             int pos;
//             cout<<"Enter the position at which you want to remove"<<endl;
//             cin>>pos;
//             l1.remove(pos);
//         }
//         else if(choice==3)
//         {
//             l1.display();
//         }
//         else{
//             cout<<"You chose to exit"<<endl;
//             break;
//         }
//     }
// }
int main()
{
    Dounly_linkedList l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(5,5);
    l1.display();
    // l1.reverse();
    l1.display();
    
}