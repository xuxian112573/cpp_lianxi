#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;
using namespace std;

int main()
{
    MatrixXd m(2,5);
    m.resize(4,3);
    cout<<"the Matrix m isof size "<<m.rows()<<"x"<<m.cols()<<endl;
    cout<<"It has "<<m.size()<<" coefficient"<<endl;
    VectorXd v(2);
    v.resize(5);
    cout<<"The vector v is of size "<<v.size()<<endl;
    cout<<"As a matrix ,vis of size "<<v.rows()<<" x "<<v.cols()<<endl;
    
    ///----------------------------
    MatrixXf a(2,2);
    cout<<"a is of size "<<a.rows()<<" x "<<a.cols()<<endl;
    
    MatrixXf b(3,3);
    cout<<"b is of size "<<b.rows()<<" x "<<b.cols()<<endl;
    a=b;
    cout<<"a is of size "<<a.rows()<<" x "<<a.cols()<<endl;
}
