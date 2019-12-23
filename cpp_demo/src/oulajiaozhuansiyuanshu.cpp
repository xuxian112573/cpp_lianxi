#include<iostream>
#include<math.h>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    double R=-1.62964,P=-1.00116,Y=-1.38077 ;
    double sr,sp,sy,cr,cp,cy;
    double Rol[9];
    Matrix3d mat;
    Matrix4d mat2;
    sr=sin(R);
    sp=sin(P);
    sy=sin(Y);
    cr=cos(R);
    cp=cos(P);
    cy=cos(Y);
    
    
    
    Rol[0]=cr*cp;
    
    Rol[1]=cr*sp*sy-sr*cy;
    
    Rol[2]=cr*sp*cy+sr*sy;
    
    
    Rol[3]=sr*cp;
    
    Rol[4]=sr*sp*sy+cr*cy;
    
    Rol[5]=sr*sp*cy-cr*sy;
    
    
    Rol[6]=-sp;
    
    Rol[7]=cp*sy;
    
    Rol[8]=cp*cy;
    
    
    double jx=atan2(Rol[7],Rol[8]);
    
    double jy=atan2(-Rol[6],sqrt((Rol[7])*(Rol[7])+(Rol[8])*(Rol[8])));
    
    double jz=atan2(Rol[3],Rol[0]);
    mat<<Rol[0],Rol[1],Rol[2],Rol[3],Rol[4],Rol[5],Rol[6],Rol[7],Rol[8];
    
    cout<<"mat:= "<<mat<<endl;
    //四元数
    double w,x,y,z,xu;
    w=0.5*sqrt(1+Rol[0]+Rol[4]+Rol[8]);
    
    x=(Rol[7]-Rol[5])/(4*w);
    
    y=(Rol[2]-Rol[6])/(4*w);
    
    z=(Rol[3]-Rol[1])/(4*w);
    cout<<"四元数---x:  "<<x<<endl;
    cout<<"四元数---y:  "<<y<<endl;
    cout<<"四元数---z:  "<<z<<endl;
    cout<<"四元数---w:  "<<w<<endl;
    
     
    
    
    
    
    return 0;
}
