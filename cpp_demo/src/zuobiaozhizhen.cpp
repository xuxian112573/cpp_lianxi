#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int array_071[5][6];
    int (*point)[6]=array_071;
    int *pointp[5];
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            array_071[i][j]=i+j;
            cout<<array_071[i][j];
        }
        cout<<endl;
    }
    cout<<"*(*(point+2)+4)的元素为： "<<*(*(point+2)+4)<<endl;
    cout<<"*(*(point+0)+4)的元素为： "<<*(*(point+0)+4)<<endl;
    
    cout<<"*(point[2]+4)的元素为： "<<*(point[2]+4)<<endl;
    
    cout<<"(*(point+2))[4]: "<<(*(point+2))[4]<<endl;
    cout<<"point[2][4]: "<<point[2][4]<<endl;
    
    for(int i=0;i<5;i++)
    {
        pointp[i]=array_071[i];
    }
    cout<<"*(*(pointp+2)+4)的元素为： "<<*(*(pointp+2)+5)<<endl;
    cout<<"*(*(pointp+0)+4)的元素为： "<<*(*(pointp+0)+5)<<endl;
    
    cout<<"*(pointp[2]+4)的元素为： "<<*(pointp[2]+5)<<endl;
    
    cout<<"(*(pointp+2))[4]: "<<(*(pointp+2))[4]<<endl;
    cout<<"pointp[2][4]: "<<pointp[2][4]<<endl;
    return 0;
}
