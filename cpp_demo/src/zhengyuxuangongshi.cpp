#include<iostream>
#include<math.h>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    double R=0,P=-1.5646,Y=0;
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
    
    //cout<<"sr=: "<<sr<<endl;
    //cout<<"sp=: "<<sp<<endl;
    //cout<<"sy=: "<<sy<<endl;
    //cout<<"cr=: "<<cr<<endl;
    //cout<<"cp=: "<<cp<<endl;
    //cout<<"cy=: "<<cy<<endl;
    
    Rol[0]=cr*cp;
    //cout<<"r11=: "<<Rol[0]<<endl;
    Rol[1]=cr*sp*sy-sr*cy;
    //cout<<"r12=: "<<Rol[1]<<endl;
    Rol[2]=cr*sp*cy+sr*sy;
    //cout<<"r13=: "<<Rol[2]<<endl;
    
    Rol[3]=sr*cp;
    //cout<<"r21=: "<<Rol[3]<<endl;
    Rol[4]=sr*sp*sy+cr*cy;
    //cout<<"r22=: "<<Rol[4]<<endl;
    Rol[5]=sr*sp*cy-cr*sy;
    //cout<<"r23=: "<<Rol[5]<<endl;
    
    Rol[6]=-sp;
    //cout<<"r31=: "<<Rol[6]<<endl;
    Rol[7]=cp*sy;
    //cout<<"r32=: "<<Rol[7]<<endl;
    Rol[8]=cp*cy;
    //cout<<"r33=: "<<Rol[8]<<endl;
    
    double jx=atan2(Rol[7],Rol[8]);
    
    double jy=atan2(-Rol[6],sqrt((Rol[7])*(Rol[7])+(Rol[8])*(Rol[8])));
    
    double jz=atan2(Rol[3],Rol[0]);
    cout<<"R=: "<<180*jz/3.1415926<<endl;
    cout<<"P=: "<<180*jy/3.1415926<<endl;
    cout<<"Y=: "<<180*jx/3.1415926<<endl;
    //四元数
    double w,x,y,z,xu;
    w=0.5*sqrt(1+Rol[0]+Rol[4]+Rol[8]);
    
    x=(Rol[7]-Rol[5])/(4*w);
    cout<<"x=: "<<x<<endl;
    y=(Rol[2]-Rol[6])/(4*w);
    cout<<"y=: "<<y<<endl;
    z=(Rol[3]-Rol[1])/(4*w);
    cout<<"z=: "<<z<<endl;
    cout<<"w=: "<<w<<endl;
    xu=x*x+y*y+z*z+w*w;
    //cout<<"xu=: "<<xu<<endl;
    mat<<Rol[0],Rol[1],Rol[2],Rol[3],Rol[4],Rol[5],Rol[6],Rol[7],Rol[8];
    cout<<"mat=: \n"<<mat<<endl;
    mat2<<Rol[0],Rol[1],Rol[2],0,Rol[3],Rol[4],Rol[5],0,Rol[6],Rol[7],Rol[8],0,0,0,0,1;
    cout<<"mat2=: \n"<<mat2<<endl;
    cout<<"mat2逆矩阵=: \n"<<mat2.inverse()<<endl;
    
    
    
    
    
    return 0;
}
