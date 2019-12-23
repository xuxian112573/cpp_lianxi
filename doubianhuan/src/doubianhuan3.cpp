#include<iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>

int main()
{

    Eigen::Matrix4d m,l;
    m(3,0)=0;m(3,1)=0;m(3,2)=0;m(3,3)=1;
    Eigen::MatrixXd n(4,1),z(4,1);
    n<<616.811,-45.5606,677.071,1;
    z<<618.698,-158.138,419.744,1;
    l=n.inverse();
    
    return 0;
    
    
}
