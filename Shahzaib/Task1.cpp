#include<iostream>
#include<string>
using namespace std;
class Doctor
{
  private:
     int doc_ID;
     string docName; 
     string specialization;
  public:
      Doctor(int x=0 , string y="", string z="" )
      {
        doc_ID=x;
        docName=y;
        specialization=z;
      }; //constructor

    void getter()
    {
        cout<<"Doc_ID : "<<doc_ID<<endl;
        cout<<"Doc_Name : "<<docName<<endl;
        cout<<"DOC Specialization : "<<specialization<<endl;
    }
       void setter(int X, string y, string z)
    {
        doc_ID=X;
        docName=y;
        specialization=z;
    }
      // other functions
};

class patient
 {
private:
    string ptName;         
    int age;    
    int doc_ID;    

public:
    patient(string X="", int y=0, int z=0)
    {
        ptName=X;
        age=y;
        doc_ID=z;
    }  //constructor
    // void setter(string x,int y)
    // {

    // }
    void getter()
    {
        cout<<"ptName : "<<ptName<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"DOC ID : "<<doc_ID<<endl;
    }
    void setter(string X, int y, int z)
    {
        ptName=X;
        age=y;
        doc_ID=z;
    }
    // other functions
};


int main()
{
    Doctor d1[8];
    patient p1[15];
    d1[0].setter(1,"Shahzaib","Heart surgeon");
    d1[1].setter(2,"Shahzad","Heart surgeon");
    d1[2].setter(1,"Shahzaib","Heart surgeon");
    d1[3].setter(1,"Shahzaib","Heart surgeon");
    d1[4].setter(1,"Shahzaib","Heart surgeon");
    d1[5].setter(1,"Shahzaib","Heart surgeon");
    d1[6].setter(1,"Shahzaib","Heart surgeon");
    d1[7].setter(1,"Shahzaib","Heart surgeon");
    // d1[8].setter(1,"Shahzaib","Heart surgeon");
    
    
}