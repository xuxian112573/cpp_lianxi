#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
    Matrix2d a;
    a<<1,2,
       3,4;
    MatrixXd b(2,2);
    b<<2,3,
       1,4;
    cout<<"a+b=\n"<<a+b<<endl;
    cout<<"a-b=\n"<<a-b<<endl;
    cout<<"a+=b\n"<<endl;
    a+=b;
    cout<<"a=: "<<endl<<a<<endl;
    
    Vector3d v(1,2,3);
    Vector3d w(1,0,0);
    cout<<"v=: "<<v<<endl;
    cout<<"w=: "<<w<<endl;
    cout<<"-v+w-v=\n"<<-v+w-v<<endl;
}
