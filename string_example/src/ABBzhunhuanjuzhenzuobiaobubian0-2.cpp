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
    Mat0=goujianfangzhen(358.811,-83.2699,451.058,0.728768,-0.275307,0.615326,-0.120318);
   // cout<<"方阵MAT0:= \n"<<Mat0<<endl;
    Mat1=Mat0.inverse();
    //cout<<"方阵MAT0逆矩阵:= \n"<<Mat1<<endl;
    Mat2=goujianfangzhen(392.077,-40.174,208.215,0.0621836,-0.988768,-0.130385,-0.0383605);
    //cout<<"方阵MAT2:= \n"<<Mat2<<endl;
    Mat3=Mat1*Mat2;
    RPY(Mat3);
    cout<<"变换矩阵Mat3:= \n"<<Mat3<<endl;
    
    
    cout<<"test====2-----"<<endl;
    Eigen::Matrix4d Mat4,Mat5,Mat6,Mat7,Mat8;
   
    Mat4=goujianfangzhen(448.933,276.914,625.171,0.728743,-0.275309,0.615358,-0.120299);
    //cout<<"方阵MAT4:= \n"<<Mat4<<endl;
    Mat5=Mat4.inverse();
    //cout<<"方阵MAT5逆矩阵:= \n"<<Mat5<<endl;
    Mat6=goujianfangzhen(482.18,319.983,382.307,0.0621359,-0.988773,-0.130382,-0.03831);
    //cout<<"方阵MAT6:= \n"<<Mat6<<endl;
    Mat7=Mat5*Mat6;
    RPY(Mat7);
    cout<<"变换矩阵Mat7:= \n"<<Mat7<<endl;
    
    
    cout<<"test3-----"<<endl;
    Eigen::Matrix4d Mat9,Mat10,Mat11,Mat12;
    Mat9=goujianfangzhen(451.575,146.903,549.16,0.728679,-0.275391,0.615388,-0.120351);
    Mat10=Mat9.inverse();
    Mat11=goujianfangzhen(484.79,189.953,306.3,0.0620992,-0.988778,-0.130383,-0.0382457);
    Mat12=Mat10*Mat11;
    RPY(Mat12);
    cout<<"变换矩阵Mat12:= \n"<<Mat12<<endl;
    
    cout<<"test4-----"<<endl;
    Eigen::Matrix4d Mat13,Mat14,Mat15,Mat16;
    Mat13=goujianfangzhen(549.576,-51.7846,656.137,0.728564,-0.275674,0.615422,-0.120222);
    Mat14=Mat13.inverse();
    Mat15=goujianfangzhen(582.692,-8.79534,413.254,0.0619778,-0.988762,-0.130619,-0.0380485);
    Mat16=Mat14*Mat15;
    RPY(Mat16);
    cout<<"变换矩阵Mat16:= \n"<<Mat16<<endl;
    
    cout<<"test5-----"<<endl;
    Eigen::Matrix4d Mat17,Mat18,Mat19,Mat20;
    Mat17=goujianfangzhen(551.298,41.8071,514.889,0.728526,-0.275637,0.615492,-0.120183);
    Mat18=Mat17.inverse();
    Mat19=goujianfangzhen(584.377,84.7916,271.999,0.0619879,-0.988768,-0.130588,-0.0379716);
    Mat20=Mat18*Mat19;
    RPY(Mat20);
    cout<<"变换矩阵Mat20:= \n"<<Mat20<<endl;
    
    //Mat8=Mat12*Mat7;
    //cout<<"矩阵8： =\n"<<Mat8<<endl;
    return 0;
}
