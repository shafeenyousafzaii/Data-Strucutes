#include<iostream>
#include<string>
#include"Array-based-list.h"
using namespace std;
arrayList::arrayList(int c)
{
    capacity=c;
    arr=new int[c];
    // arr.length();
    curr=NULL;
    len=0;
}
arrayList::~arrayList()
{
    delete [] arr ;
    arr=NULL;
}
void arrayList::insert(int val, int pos)
{
   if(capacity==len)
   {
    cout<<"FUll"<<endl;
   }
   if(pos<1 || pos>len+1)
   {
    cout<<"Invalid"<<endl;
   }
   tail();
   for(int i=len ; i >= pos ; i--)
   {
     *(curr+1)=*curr;
     back();
   }
   *(curr+1)=val;
   len++;
}
void arrayList::back()
{
    curr--;
}
void arrayList::start()
{
    curr=arr;
}
void arrayList::tail()
{
    curr=&curr[len];
}
void arrayList::next()
{
    curr++;
}
