#include<iostream>
using namespace std;
int main()
{
   double x=0.15;
   double y=0.15; 
   
   
    for(int i=0;i<3;i++)
    {
        
        
        for(int j=0;j<3;j++)
        {
            cout<<"y= "<<y<<"  "<<"x= "<<x<<endl;
            
            x-=0.15;
            
        }
        y-=0.15;
        x=0.15;
    }
    return 0;
}
