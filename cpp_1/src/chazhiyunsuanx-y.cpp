#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    double i,j,k;
    double x,z,y;
    y=57;
    ofstream outfile1("/home/xu/Desktop/cpp_lianxi/text/peng2.txt",std::ios::app);
        
    for(i=0.2;i<=56.2;)
    {
        for(j=0.2;j<=56.2;)
        {
            x=i;
            z=j;
            outfile1 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile1.close();
    y=0;
    ofstream outfile2("/home/xu/Desktop/cpp_lianxi/text/peng3.txt",std::ios::app);
        
    for(i=0.2;i<=56.2;)
    {
        for(j=0.2;j<=56.2;)
        {
            x=i;
            z=j;
            outfile2 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile2.close();
    
    x=57;
    ofstream outfile3("/home/xu/Desktop/cpp_lianxi/text/peng4.txt",std::ios::app);
        
    for(i=0.2;i<=56.2;)
    {
        for(j=0.2;j<=56.2;)
        {
            y=i;
            z=j;
            outfile3 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile3.close();
   x=0;
    ofstream outfile4("/home/xu/Desktop/cpp_lianxi/text/peng5.txt",std::ios::app);
        
    for(i=0.2;i<=56.2;)
    {
        for(j=0.2;j<=56.2;)
        {
            y=i;
            z=j;
            outfile4 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile4.close();
    
    z=0;
    ofstream outfile5("/home/xu/Desktop/cpp_lianxi/text/peng6.txt",std::ios::app);
        
    for(i=0;i<=57.2;)
    {
        for(j=0;j<=57.2;)
        {
            x=i;
            y=j;
            outfile5 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile5.close();
   z=57;
    ofstream outfile6("/home/xu/Desktop/cpp_lianxi/text/peng1.txt",std::ios::app);
        
    for(i=0;i<=57.2;)
    {
        for(j=0;j<=57.2;)
        {
            x=i;
            y=j;
            outfile6 << x<<" "<<y<<"  "<<z<< std::endl;
            j+=0.2;
        }
        i+=0.2;
    }
    outfile6.close();
    
    
    return 0;
}
