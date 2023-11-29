#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

  bool checkint(int a)
    {
        int count;
        if (abs(a - round(a)) > 0.00001) 
        {
        count=0;
    } 
    else
     {
        count=1;
     }
        if(count==1)
        {
            return true;
        }
        else
        return false;
    }

int count_compass_angles(int start, int end) {
    int count = 0;
    float angle1=0;
    int angle2=0;
    float angle3=0;
    float start_angle=start;
    float end_angle=end;
    for(int i= start;i<=end;i++)
    {
        angle1=(start_angle+end_angle)/2;
        start_angle=end_angle;
        end_angle=angle1;
        // angle3=end_angle;
        // angle2=(angle3+angle1)/2;
         if(angle1<=end)
         {
            angle3=end_angle;
         }
        
        cout<<angle1<<" ";
        // cout<<angle2<<" ";
        // if(checkint(!angle2))
        // {
        //     count++;
        // }
        if(checkint(angle1))
        {
            count++;
        }
       
    }
    return count;
}

int main() {
    float start, end;
    cin >> start >> end;
    cout << count_compass_angles(start, end) << endl;
    return 0;
}   
