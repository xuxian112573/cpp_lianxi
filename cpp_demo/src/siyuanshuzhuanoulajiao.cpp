#include<iostream>
#include<math.h>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    double x,y,z,w;
    double arfa,beta,gama;
    x=0.65250;
    y=-0.15267;
    z=0.70182;
    w=-0.24162;
    arfa=atan2(2*(w*x+y*z),1-2*(x*x+y*y));
    beta=asin(2*(w*y-z*x));
    gama=atan2(2*(w*z+x*y),1-2*(y*y+z*z));
    
    
    
    cout<<"R-gama=: "<<gama<<" rad"<<endl;
    cout<<"P-beta=: "<<beta<<" rad"<<endl;
    cout<<"Y-arfa=: "<<arfa<<" rad"<<endl;
    
    
    
    return 0;
}
