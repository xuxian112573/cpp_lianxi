#include<iostream>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix2d mat;
    mat<<1,2,
         3,4;

    cout<<"求和： \n"<<mat.sum()<<endl;
    cout<<"乘积： \n"<<mat.prod()<<endl;
    cout<<"平均值： \n"<<mat.mean()<<endl;
    cout<<"最小值： \n"<<mat.minCoeff()<<endl;
    cout<<"最大值： \n"<<mat.maxCoeff()<<endl;
    cout<<"迹： \n"<<mat.trace()<<endl;
}
