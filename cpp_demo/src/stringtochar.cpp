#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    char buf[10];
    string str("abdleis");
    int length=str.copy(buf,strlen(buf)-1);
    buf[length]='\0';
    cout<<buf<<endl;
   return 0;
}
