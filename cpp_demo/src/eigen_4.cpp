#include<iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix2i a,b,c,d;
    a<<1,2,
       3,4;
    b=a.transpose();
    cout<<"a的转置为: \n"<<b<<endl;
    c=a.conjugate();
    cout<<"a的共轭为： \n"<<c<<endl;
    d=a.adjoint();
    cout<<"a的共轭转置为： \n"<<d<<endl;
    return 0;
}

