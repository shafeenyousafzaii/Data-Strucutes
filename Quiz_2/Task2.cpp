#include<iostream>
#include<string.h>
#include<string>
#include"Task2.h"
using namespace std;
int main()
{
    Stack_List sl1;
    while(1)
    {
        cout<<"Welcome to the cave"<<endl;
        cout<<"Must put you location info in a stack so that you can go back whenever you see a ghost "<<endl;
        cout<<"Enter a choice:"<<endl;
        cout<<"1. Go forward in the cave"<<endl;
        cout<<"2. Go back"<<endl;
        cout<<"3. Run from the cave....I saw the ghost"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            char name;
            cout<<"Mark your current location so that you can go back"<<endl;
            cout<<"Enter the name of your current location"<<endl;
            cin.ignore();
            cin>>name;
            sl1.push(name);
        }
        else if(choice==2)
        {
            char s;
            s=sl1.pop();
            cout<<"You are now at : "<<s<<endl;
        }
        else if(choice==3)
        {
            sl1.pop(1);
            cout<<"You successfully ran away from the cave"<<endl;
            
        }
        else
            {
                cout<<"You entered the wrong input"<<endl;
                continue;
            }
    }
}