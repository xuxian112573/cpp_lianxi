#include<iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    ArrayXXf m(2,2);
    m(0,0)=1.0;
    m(0,1)=2.0;
    m(1,0)=3.0;
    m(1,1)=m(0,1)+m(1,0);
    
    cout<<m<<endl;
    cout<<endl;
    
    m<<1.0,2.0,
       3.0,4.0;
       
    cout<<m<<endl;
}
