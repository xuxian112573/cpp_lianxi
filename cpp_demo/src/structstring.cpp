#include<iostream>
#include<string>

struct inflatable
{

    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable guest=
    {
        "xuxian",
        1.88,
        299.99
        
    };
    
    inflatable pal=
    {
        "jinpeng",
        3.21,
        32.99
    };
    
    cout<<"xujin = "<<guest.name<<endl;
    cout<<"  --"<<guest.volume<<endl;
    cout<<"  --"<<guest.price<<endl;
    return 0;
}
