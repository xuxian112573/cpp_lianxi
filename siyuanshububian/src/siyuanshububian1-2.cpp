#include<iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>

#define PI (3.1415926535897932346f)
using namespace std;


Eigen::Matrix4d  goujianfangzhen(double x,double y,double z,double q_x,double q_y,double q_z,double q_w)
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
    //cout<<"欧拉角：= \n"<<ea3<<endl<<endl;
    
    
    Eigen::Vector3d ea2;
    ea2=ea3;
    
    Eigen::Matrix3d R2;
    R2=Eigen::AngleAxisd(ea2[0],Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea2[1],Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea2[2],Eigen::Vector3d::UnitX());
    
    
    
    
    Eigen::Quaterniond q0;
    
    q0=R2;
    
    
    Eigen::Matrix4d M0,M1,M2,M3;
    M0(0,0)=R2(0,0);M0(0,1)=R2(0,1);M0(0,2)=R2(0,2);M0(0,3)=x;
    M0(1,0)=R2(1,0);M0(1,1)=R2(1,1);M0(1,2)=R2(1,2);M0(1,3)=y;
    M0(2,0)=R2(2,0);M0(2,1)=R2(2,1);M0(2,2)=R2(2,2);M0(2,3)=z;
    M0(3,0)=0;M0(3,1)=0;M0(3,2)=0;M0(3,3)=1;
    //cout<<"方阵M0:= \n"<<M0<<endl;
    return M0;
    //exit;
      
}

Eigen::Vector3d RPY(Eigen::Matrix4d m)
{
    Eigen::Vector3d n;
    Eigen::Matrix3d Rx;
    Rx(0,0)=m(0,0);Rx(0,1)=m(0,1);Rx(0,2)=m(0,2);
    Rx(1,0)=m(1,0);Rx(1,1)=m(1,1);Rx(1,2)=m(1,2);
    Rx(2,0)=m(2,0);Rx(2,1)=m(2,1);Rx(2,2)=m(2,2);
    n=Rx.eulerAngles(2,1,0);
    cout<<"欧拉角：= \n"<<n<<endl<<endl;
    return n;
}
int main()
{
    cout<<"test ---1-----"<<endl;
    Eigen::Matrix4d Mat1,Mat3,Mat2,Mat0;
    Mat0=goujianfangzhen(645.163,-143.655,424.309,0.233098,0.965985,0.108365,0.0282011);
   // cout<<"方阵MAT0:= \n"<<Mat0<<endl;
    Mat1=Mat0.inverse();
    //cout<<"方阵MAT0逆矩阵:= \n"<<Mat1<<endl;
    Mat2=goujianfangzhen(600.224,34.0487,434.302,0.110097,-0.987503,-0.112564,0.00683699);
    //cout<<"方阵MAT2:= \n"<<Mat2<<endl;
    Mat3=Mat1*Mat2;
    RPY(Mat3);
    cout<<"变换矩阵Mat3:= \n"<<Mat3<<endl;
    
    
    cout<<"test====2-----"<<endl;
    Eigen::Matrix4d Mat4,Mat5,Mat6,Mat7,Mat8;
   
    Mat4=goujianfangzhen(647.33,-143.668,424.77,0.233584,0.965852,0.107336,0.032364);
    //cout<<"方阵MAT4:= \n"<<Mat4<<endl;
    Mat5=Mat4.inverse();
    //cout<<"方阵MAT5逆矩阵:= \n"<<Mat5<<endl;
    Mat6=goujianfangzhen(602.312,34.0438,434.37,0.109607,-0.987526,-0.113015,0.00257295);
    //cout<<"方阵MAT6:= \n"<<Mat6<<endl;
    Mat7=Mat5*Mat6;
    RPY(Mat7);
    cout<<"变换矩阵Mat7:= \n"<<Mat7<<endl;
    
    
    cout<<"test3-----"<<endl;
    Eigen::Matrix4d Mat9,Mat10,Mat11,Mat12;
    Mat9=goujianfangzhen(642.379,-143.656,423.587,0.226314,0.965976,0.121864,-0.0286476);
    Mat10=Mat9.inverse();
    Mat11=goujianfangzhen(598.928,34.0493,438.792,0.11655,-0.985392,-0.105874,0.0648847);
    Mat12=Mat10*Mat11;
    RPY(Mat12);
    cout<<"变换矩阵Mat12:= \n"<<Mat12<<endl;
    
    cout<<"test4-----"<<endl;
    Eigen::Matrix4d Mat13,Mat14,Mat15,Mat16;
    Mat13=goujianfangzhen(619.078,-33.937,681.034,0.665694,-0.240748,0.703112,-0.067272);
    Mat14=Mat13.inverse();
    Mat15=goujianfangzhen(642.344,-143.654,423.517,0.216637,0.968052,0.122669,-0.0299325);
    Mat16=Mat14*Mat15;
    RPY(Mat16);
    cout<<"变换矩阵Mat16:= \n"<<Mat16<<endl;
    
    cout<<"test5-----"<<endl;
    Eigen::Matrix4d Mat17,Mat18,Mat19,Mat20;
    Mat17=goujianfangzhen(619.558,-44.8441,677.584,0.670333,-0.22536,0.705184,-0.0508085);
    Mat18=Mat17.inverse();
    Mat19=goujianfangzhen(642.27,-142.563,415.23,0.194111,0.972767,0.123509,-0.028117);
    Mat20=Mat18*Mat19;
    RPY(Mat20);
    cout<<"变换矩阵Mat20:= \n"<<Mat20<<endl;
    
    
    return 0;
}
