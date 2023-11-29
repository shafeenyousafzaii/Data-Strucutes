#include<iostream>
#include<string>
using namespace std;
bool check_palindrome(string name);
void check_frequency(string name);
int main()
{
    string name;
    // string *ptr;
    // ptr=&name;
    int choice;
    while(choice!=3)
    {
      cout<<"Enter your name:"<<endl;
      cin>>name;
      cout<<name;
      cout<<"Enter 1 to check if it is a pelindrome"<<endl;
      cout<<"Enter 2 to check the frequency of a certain character"<<endl;
      cout<<"Enter 3 to exit"<<endl;
      cin>>choice;
      if(choice==1)
      {
        // check_palindrome(name);
        if(check_palindrome(name)==true)
        {
          cout<<"It is a palindrome"<<endl;
        }
        else
        {
          cout<<"It is not a palindrome"<<endl;
        }
      }
      else if(choice=2)
      {
        check_frequency(name);
      }
      else if(choice==3)
      {
        break;
      }
    }
}
bool check_palindrome(string &ptr)
{
    char*ptrr;
    ptrr=&ptr[0];
    char*ptr2;
    int last=ptr.length()-1;
    ptr2=&ptr[last];
    // ptr2=&ptr[ptr->end()-1];
    int count=0;
    for(int i = 0 ; i < ptr.length() ; i++ )
    {
        if(*ptrr==*ptr2)
        {
            count++;
            if (count==(ptr.length()/2))
            {
                cout<<"It is a palindrome"<<endl;
            }
            
            return true;
        }
        
        ptrr++;
        ptr2--;

    }
}
void check_frequency(string name)
{

}