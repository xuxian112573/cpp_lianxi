#include<iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>

#define PI (3.1415926535897932346f)
using namespace std;


Eigen::Matrix4d  goujianfangzhen(double x,double y,double z,double q_w,double q_x,double q_y,double q_z)
{
    Eigen::Quaterniond q3;
    q3.x()=q_x;
    q3.y()=q_y;
    q3.z()=q_z;
    q3.w()=q_w;
    
    //四元数转旋转矩阵
    Eigen::Matrix3d R2=q3.toRotationMatrix();
    //cout<<"旋转矩阵 R2=: \n"<<R2<<endl;
    //Eigen::Vector3d ea3=R3.eulerAngles(2,1,0);
    //cout<<"欧拉角：= \n"<<ea3<<endl<<endl;
    
    
    //Eigen::Vector3d ea2;
    //ea2=ea3;
    
    //Eigen::Matrix3d R2;
    //R2=Eigen::AngleAxisd(ea2[0],Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea2[1],Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea2[2],Eigen::Vector3d::UnitX());
    
    
    
    
   // Eigen::Quaterniond q0;
    
    //q0=R2;
    
    
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
    Mat0=goujianfangzhen(618.698,-158.138,419.744,0.217077,0.961368,0.151874,-0.0747296);
   // cout<<"方阵MAT0:= \n"<<Mat0<<endl;
    Mat1=Mat0.inverse();
    //cout<<"方阵MAT0逆矩阵:= \n"<<Mat1<<endl;
    Mat2=goujianfangzhen(570.484,17.7273,440.882,0.123787,-0.978078,-0.118368,0.118445);
    //cout<<"方阵MAT2:= \n"<<Mat2<<endl;
    Mat3=Mat1*Mat2;
    cout<<"变换矩阵Mat3:= \n"<<Mat3<<endl;
    
    
    cout<<"test====2-----"<<endl;
    Eigen::Matrix4d Mat4,Mat5,Mat6,Mat7,Mat8;
   
    Mat4=goujianfangzhen(640.762,-188.629,439.532,0.307782,0.920968,0.230418,-0.0632117);
    //cout<<"方阵MAT4:= \n"<<Mat4<<endl;
    Mat5=Mat4.inverse();
    //cout<<"方阵MAT5逆矩阵:= \n"<<Mat5<<endl;
    Mat6=goujianfangzhen(561.233,-23.4682,429.679,0.0250375,-0.970915,-0.196469,0.134526);
    //cout<<"方阵MAT6:= \n"<<Mat6<<endl;
    Mat7=Mat5*Mat6;
    //RPY(Mat7);
    cout<<"变换矩阵Mat7:= \n"<<Mat7<<endl;
    
    
    cout<<"test3-----"<<endl;
    Eigen::Matrix4d Mat9,Mat10,Mat11,Mat12;
    Mat9=goujianfangzhen(658.125,-31.0591,421.095,0.0233871,0.980145,0.194255,0.032161);
    Mat10=Mat9.inverse();
    Mat11=goujianfangzhen(587.434,116.754,503.884,0.312432,-0.929382,-0.193894,0.0322595);
    Mat12=Mat10*Mat11;
    //RPY(Mat11);
    cout<<"变换矩阵Mat12:= \n"<<Mat12<<endl;
    
    cout<<"test4-----"<<endl;
    Eigen::Matrix4d Mat13,Mat14,Mat15,Mat16;
    Mat13=goujianfangzhen(598.759,-99.9193,401.987,0.0340868,0.990903,-0.102544,-0.0802111);
    Mat14=Mat13.inverse();
    Mat15=goujianfangzhen(641.368,60.4714,480.467,0.304955,-0.943622,0.123388,0.0368295);
    Mat16=Mat14*Mat15;
    //RPY(Mat15);
    cout<<"变换矩阵Mat16:= \n"<<Mat16<<endl;
    
    cout<<"test5-----"<<endl;
    Eigen::Matrix4d Mat17,Mat18,Mat19,Mat20;
    Mat17=goujianfangzhen(589.451,-334.679,569.106,0.537252,0.837161,-0.0673937,-0.0773313);
    Mat18=Mat17.inverse();
    Mat19=goujianfangzhen(608.707,-186.005,463.157,0.22036,0.970358,-0.0875201,-0.0467679);
    Mat20=Mat18*Mat19;
    //RPY(Mat20);
    cout<<"变换矩阵Mat20:= \n"<<Mat20<<endl;
    
    
    return 0;
}
