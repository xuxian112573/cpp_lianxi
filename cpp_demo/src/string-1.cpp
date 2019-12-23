#include<string>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s1,s2,s3;
    s1="123hse";
    s2="8900hjher";
    s3=s1+s2;
    char c[18];
    char d[18]="hflkhrrh";
    strcpy(c,d);
    
    cout<<s3<<endl;
    s1+=s2;
    cout<<"s1=: "<<s1<<endl;
    s2+=s1;
    cout<<"s2=: "<<s2<<endl;
    strcat(c,"xujinpeng");
    cout<<"c: ="<<c<<endl;
    int len1=strlen(d);
    int len2=s2.size();
    
    cout<<len1<<endl;
    cout<<len2<<endl;
    return 0;
}

