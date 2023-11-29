#include<iostream>
#include<string>
#include"Task3.h"
using namespace std;
int main()
{
    List l1,l2;
    string name;
    cout<<"Welcome to undoing and redoing your string"<<endl;
    cout<<"Enter a name"<<endl;
    cin>>name;
    for(int i = 0 ; i < name.length() ; i++)
    {
        int charr=name[i];
        l1.push(charr);
    }
    int choice;
    while(1)
    {
        cout<<"Enter a choice"<<endl;
        cout<<"1) Undo"<<endl;
        cout<<"2) Redo"<<endl;
        cin>>choice;
        if(choice==1)
        {
            int charr;
            charr=l1.pop();
            l2.push(charr);
            l1.display();
        }
        else if(choice==2)
        {
            int charr;
            charr=l2.pop();
            l1.push(charr);
            int charrr;
            l1.display();
            
        }
        else{
            break;
        }

    }
}