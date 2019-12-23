#include<string>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char a[]="12345678afke";
    std::string buf(a,a+strlen(a));
    std::string buf2(a);
    std::string buf3=a;
    cout<<buf2<<endl;
    return 0;
}
