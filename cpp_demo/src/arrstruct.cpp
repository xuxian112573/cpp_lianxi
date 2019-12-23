#include<iostream>
#include<string>

using namespace std;
struct inflatable
{
    char name[64];
    float volume;
    double price;
};

int main()
{
    inflatable guest[2]=
    {
        {"babab",0.5,21},
        {"jinpeng",0.6,98}
    };
    
    cout<<guest[0].name<<"  "<<guest[1].name<<endl;
    //cout<guest[1].volume<<" "<<guest[1].price<<endl;
    return 0;
}
