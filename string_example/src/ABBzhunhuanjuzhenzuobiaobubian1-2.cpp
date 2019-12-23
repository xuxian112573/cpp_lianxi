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
    Mat0=goujianfangzhen(441.438,-216.645,218.004,0.278583,0.951062,0.109587,0.0765756);
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
   
    Mat4=goujianfangzhen(531.672,143.487,392.25,0.278693,0.95102,0.109569,0.0767225);
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
    Mat9=goujianfangzhen(534.284,13.456,316.254,0.278733,0.95101,0.109592,0.0766628);
    Mat10=Mat9.inverse();
    Mat11=goujianfangzhen(484.79,189.953,306.3,0.0620992,-0.988778,-0.130383,-0.0382457);
    Mat12=Mat10*Mat11;
    RPY(Mat12);
    cout<<"变换矩阵Mat12:= \n"<<Mat12<<endl;
    
    cout<<"test4-----"<<endl;
    Eigen::Matrix4d Mat13,Mat14,Mat15,Mat16;
    Mat13=goujianfangzhen(632.275,-185.265,423.246,0.278843,0.950953,0.10988,0.0765577);
    Mat14=Mat13.inverse();
    Mat15=goujianfangzhen(582.692,-8.79534,413.254,0.0619778,-0.988762,-0.130619,-0.0380485);
    Mat16=Mat14*Mat15;
    RPY(Mat16);
    cout<<"变换矩阵Mat16:= \n"<<Mat16<<endl;
    
    cout<<"test5-----"<<endl;
    Eigen::Matrix4d Mat17,Mat18,Mat19,Mat20;
    Mat17=goujianfangzhen(633.952,-91.6807,281.982,0.278835,0.950962,0.109877,0.0764748);
    Mat18=Mat17.inverse();
    Mat19=goujianfangzhen(584.377,84.7916,271.999,0.0619879,-0.988768,-0.130588,-0.0379716);
    Mat20=Mat18*Mat19;
    RPY(Mat20);
    cout<<"变换矩阵Mat20:= \n"<<Mat20<<endl;
    
    //Mat8=Mat12*Mat7;
    //cout<<"矩阵8： =\n"<<Mat8<<endl;
    return 0;
}
