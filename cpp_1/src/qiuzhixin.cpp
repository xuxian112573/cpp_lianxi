#include<iostream>
#include<string>
using namespace std;
struct Point
{
    double x;
    double y;
    double z;
};
struct inflatable
{
    char name[64];
    float volume;
    double price;
};
int main()
{
    double point1[3];
    inflatable s1;
    Point p[10]=
    {
        {53.3617,100.843,242.354},
        {132.529,145.62,275.242},
        {39.1834,145.603,206.53},
        {28.4663,92.4999,206.419},
        {45.4732,89.9758,149.867},
        {122.55,-38.0708,389.425},
        {164.699,-38.1067,308.317},
        {146.824,133.73,355.618},
        {149.4,-104.417,369.344},
        {141.244,276.988,352.2}
    };
    
   point1[0]=(p[0].x+p[1].x+p[2].x+p[3].x+p[4].x+p[5].x+p[6].x+p[7].x+p[8].x+p[9].x)/10;
   
   point1[1]=(p[0].y+p[1].y+p[2].y+p[3].y+p[4].y+p[5].y+p[6].y+p[7].y+p[8].y+p[9].y)/10;
   point1[2]=(p[0].z+p[1].z+p[2].z+p[3].z+p[4].z+p[5].z+p[6].z+p[7].z+p[8].z+p[9].z)/10;
    
   cout<<"p1:= \n"<<point1[0]<<endl;
   cout<<"p1:= \n"<<point1[1]<<endl;
   cout<<"p1:= \n"<<point1[2]<<endl;
   
    return 0;
}
