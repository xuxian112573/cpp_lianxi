#include<iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;
//标量的乘除
int main()
{
    Matrix2d a;
    a<<1,2,
       3,4;
    Vector3d v(1,2,3);
    cout<<"a*2.5=\n"<<a*2.5<<endl;
    cout<<"0.1*v=\n"<<0.1*v<<endl;
    cout<<"Ding v*=2;"<<endl;
    v*=2;
    cout<<"v=: \n"<<v<<endl;
}
