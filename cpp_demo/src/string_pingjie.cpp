#include<iostream>
#include<string>


using namespace std;
string intToString(int v)
{
    char buf[32]={0};
    snprintf(buf,sizeof(buf),"%u",v);
    
    string str=buf;
    return str;
}


int main()
{
    string data;
    int mvid=7;
    string data1=intToString(mvid);
    string data2;
    data="{\"status\":200,\"id\":\""+intToString(mvid)+"\"}";
    cout<<data.c_str()<<endl;
    
    
    return 0;
}
