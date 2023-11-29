#include<iostream>
using namespace std;
int main()
{
    int TEMPERATURE[4][7];
    int *ptr;
    ptr=&TEMPERATURE[0][0];
    for(int i = 0 ; i < 28 ; i++)
    {
        
        // cout<<"Enter the temperature of day "<<i+1<<" and time "<<i+1<<endl;
        //inserting random values 
        *ptr=rand()%20+10;  
        ptr++;
        
    }
    ptr=&TEMPERATURE[0][0];
    for(int i = 0  ; i < 4  ; i++)
    {
    for(int j=0 ; j<7 ; j++)
    {
        cout<<"Temperature of week "<<i+1<<" and time "<<j+1<<" is : "<<*ptr<<endl;
        ptr++;
    }
    }
    
    ptr=&TEMPERATURE[0][0];
    //hottest day of the week
 for(int i = 0 ; i < 4 ; i++)
    {  int hottest = 0;
        for(int j= 0 ; j < 7 ;j++)
        {
            if(*ptr > hottest)
            {
                hottest = *ptr;
            }
            ptr++;
        }
        cout<< " Hottest day of week "<<i+1<<" has temperature "<<hottest<<endl;
        }

}