#include<iostream>
#include "Eigen/Dense"
#include <Eigen/SVD>
#include<cmath>
#include<math.h>
using namespace std;
using namespace Eigen;
using namespace Eigen::internal;  
using namespace Eigen::Architecture;  
struct Point
{
    double x;
    double y;
    double z;
};

MatrixXf shujuchuli(Point p[10])
{
    MatrixXf m(3,1);
    m(0,0)=(p[0].x+p[1].x+p[2].x+p[3].x+p[4].x+p[5].x+p[6].x+p[7].x+p[8].x+p[9].x)/10;
   
    m(1,0)=(p[0].y+p[1].y+p[2].y+p[3].y+p[4].y+p[5].y+p[6].y+p[7].y+p[8].y+p[9].y)/10;
    m(2,0)=(p[0].z+p[1].z+p[2].z+p[3].z+p[4].z+p[5].z+p[6].z+p[7].z+p[8].z+p[9].z)/10;
    //cout<<m<<endl;
    return m;
}

MatrixXf jian(int i,Point p[10],MatrixXf n)

{
    MatrixXf q(3,1);
    q(0,0)=p[i].x-n(0,0);
    q(1,0)=p[i].y-n(1,0);
    q(2,0)=p[i].z-n(2,0);
    return q;
}

int main()
{
    MatrixXf n(3,1),l(3,1),p(3,1),q(3,1),CentroidA(3,1),CentroidB(3,1);
    MatrixXf h(3,3),b(3,3),H(3,3);
    Point A[10]=
    {
        {53.3617,100.843,242.354},
        {132.529,145.62,275.242},
        {39.1834,145.603,206.53},
        {28.4663,92.4999,206.419},
        {45.4732,89.9758,149.867},
        {122.55,-38.0708,389.425},
        {164.699,-38.1067,308.317},
        {146.824,133.73,355.618},
        {149.4,-104.417,369.344},
        {141.244,276.988,352.2}
    };
    Point B[10]=
    {
        {685.505,190.434,470.767},
        {693.821,114.93,362.551},
        {590.363,211.248,350.075},
        {567.267,212.817,426.019},
        {489.725,158.972,302.617},
        {675.111,83.2033,525.216},
        {656.617,252.007,565.976},
        {602.549,32.9839,534.874},
        {649.104,333.586,482.071},
        {716.07,27.9724,647.56}
    };
    //计算平均值
    CentroidA=shujuchuli(A);
    CentroidB=shujuchuli(B);
    //计算协方差矩阵
    for(int j=0;j<10;j++)
    {
        
        l=jian(j,A,CentroidA);
        p=jian(j,B,CentroidB);
        h=l*p.transpose();
        //cout<<"h:=\n"<<h<<endl;
        
        H+=h;
        //cout<<"H:=\n"<<H<<endl;
        
    }
    //进行SVD进行分解
    JacobiSVD<Eigen::MatrixXf> svd(H, ComputeThinU | ComputeThinV );
    Matrix3f V = svd.matrixV(), U = svd.matrixU();
	Matrix3f  S = U.inverse() * H * V.transpose().inverse();
	
    MatrixXf R(3,3),T(3,3);
    
    double e,f,guiyishu,lanmda=0;
    MatrixXf OA(3,1),OB(3,1),OZ(3,1),c(3,1);
    for(int j=0;j<10;j++)
    {
        
        OA=jian(j,A,CentroidA);
        OB=jian(j,B,CentroidB);
        cout<<"OA:=\n"<<OA<<endl;
        cout<<"OB:=\n"<<OB<<endl;
        cout<<"-----------------"<<endl;
        f=sqrt(OA(0,0)*OA(0,0)+OA(1,0)*OA(1,0)+OA(2,0)*OA(2,0));
        cout<<"f:=\n"<<f<<endl;
        e=sqrt(OB(0,0)*OB(0,0)+OB(1,0)*OB(1,0)+OB(2,0)*OB(2,0));
        cout<<"E:=\n"<<e<<endl;
        lanmda+=e/f;
        cout<<"lanmda:=\n"<<lanmda<<endl;
    }
    guiyishu=lanmda/10;
    cout<<"guiyishu:= \n"<<guiyishu<<endl;
    R=guiyishu*V*U.transpose();
    cout<<"R---:\n"<<R<<endl;
    T=-guiyishu*R*CentroidA+CentroidB;
    cout<<"T:= \n"<<T<<endl;
    c<<53.3617,100.843,242.354;
    OZ=R*c+T;
    cout<<"OZ:=\n"<<OZ<<endl;
    return 0;
}
