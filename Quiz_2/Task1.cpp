#include <iostream>
#include <string>
#include "Task1.h"
#include<stdlib.h>
using namespace std;
int main()
{
    CircularLinkedLInst l1;
    // l1.insert(1, 1);
    // l1.insert(2, 2);
    // l1.insert(3, 3);
    // l1.insert(4, 4);
    // l1.insert(5, 2);
    // l1.insert(6, 3);
    // l1.insert(7, 4);
    // l1.remove(1);
    // l1.remove(2);
    // l1.insert(4,5);
    l1.insert(1,"Ali");
    l1.insert(2,"Amir");
    l1.insert(2,"Adnan");
    l1.insert(2,"Sohail");
    l1.insert(2,"Abdullah");
    l1.display();
    while(1)
    {
        int choice=0;
        cout<<"1:Traverse players one by one"<<endl;
        cout<<"2:Start game"<<endl;
        cout<<"3:Exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
            l1.display(1);
        }
        else if(choice==2)
        {
            cout<<"Current Players:";
            l1.display();
            // cout<<"random numbers"<<endl;
            l1.startgame();
        }
        else if(choice==3)
        {
            cout<<"You chose to exit"<<endl;
            break;
        }
        else
        {
            cout<<"You chose to exit"<<endl;
            break;
        }
    }
}