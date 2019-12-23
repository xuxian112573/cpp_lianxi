#include<iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>

#define PI (3.1415926535897932346f)
using namespace std;


Eigen::Matrix4d  goujianfangzhen(double q_x,double q_y,double q_z,double q_w)
{
    Eigen::Quaterniond q3;
    q3.x()=q_x;
    q3.y()=q_y;
    q3.z()=q_z;
    q3.w()=q_w;
    
    //四元数转旋转矩阵
    Eigen::Matrix3d R3=q3.toRotationMatrix();
    //cout<<"旋转矩阵 RX=: \n"<<R3<<endl;
    Eigen::Vector3d ea3=R3.eulerAngles(2,1,0);
    cout<<"欧拉角：= \n"<<ea3<<endl<<endl;    
    Eigen::Vector3d ea0;
    ea0=ea3;
    
    Eigen::Matrix3d R;
    R=Eigen::AngleAxisd(ea0[0],Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea0[1],Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea0[2],Eigen::Vector3d::UnitX());
    //cout<<"旋转矩阵R:= \n"<<R<<endl;
    
    
    
    Eigen::Quaterniond q1;
    
    q1=R;
    cout<<"四元数为:"<<endl;
    cout<<"x:= "<<q1.x()<<endl;
    cout<<"y:= "<<q1.y()<<endl;
    cout<<"z:= "<<q1.z()<<endl;
    cout<<"w:= "<<q1.w()<<endl;    
}
Eigen::Matrix4d  goujianfangzhen2(double q_w,double q_x,double q_y,double q_z)
{
    Eigen::Quaterniond q3;
    q3.x()=q_x;
    q3.y()=q_y;
    q3.z()=q_z;
    q3.w()=q_w;
    
    //四元数转旋转矩阵
    Eigen::Matrix3d R3=q3.toRotationMatrix();
    //cout<<"旋转矩阵 RX=: \n"<<R3<<endl;
    Eigen::Vector3d ea3=R3.eulerAngles(2,1,0);
    cout<<"欧拉角：= \n"<<ea3<<endl<<endl;  
    Eigen::Vector3d ea0;
    ea0=ea3;
    
    Eigen::Matrix3d R;
    R=Eigen::AngleAxisd(ea0[0],Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea0[1],Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea0[2],Eigen::Vector3d::UnitX());
    //cout<<"旋转矩阵R:= \n"<<R<<endl;
    
    
    
    Eigen::Quaterniond q1;
    
    q1=R;
    cout<<"四元数为:"<<endl;
    cout<<"x:= "<<q1.x()<<endl;
    cout<<"y:= "<<q1.y()<<endl;
    cout<<"z:= "<<q1.z()<<endl;
    cout<<"w:= "<<q1.w()<<endl;      
}


int main()
{
    cout<<"test ---1-----"<<endl;
    Eigen::Matrix4d Mat1,Mat3,Mat2,Mat0;
    Mat0=goujianfangzhen(-0.317061f, -0.031496f, -0.941372f, 0.110906f);
    Mat0=goujianfangzhen2(0.110906f,-0.317061f,-0.031496f,-0.941372f);
  
    return 0;
}
