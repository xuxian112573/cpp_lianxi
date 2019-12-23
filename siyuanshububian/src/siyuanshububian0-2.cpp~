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
    Mat0=goujianfangzhen(616,-45,677,-0.158494,0.774519,-0.158494,0.591506);
   // cout<<"方阵MAT0:= \n"<<Mat0<<endl;
    Mat1=Mat0.inverse();
    //cout<<"方阵MAT0逆矩阵:= \n"<<Mat1<<endl;
    Mat2=goujianfangzhen(616,-45,687,-0.158494,0.774519,-0.158494,0.591506);
    //cout<<"方阵MAT2:= \n"<<Mat2<<endl;
    Mat3=Mat1*Mat2;
    cout<<"变换矩阵Mat3:= \n"<<Mat3<<endl;
    
    
    cout<<"test====2-----"<<endl;
    Eigen::Matrix4d Mat4,Mat5,Mat6,Mat7,Mat8;
   
    Mat4=goujianfangzhen(612,-35,673,0.158494,0.591506,0.158494,0.774519);
    //cout<<"方阵MAT4:= \n"<<Mat4<<endl;
    Mat5=Mat4.inverse();
    //cout<<"方阵MAT5逆矩阵:= \n"<<Mat5<<endl;
    Mat6=goujianfangzhen(612,-35,683,0.158494,0.591506,0.158494,0.774519);
    //cout<<"方阵MAT6:= \n"<<Mat6<<endl;
    Mat7=Mat5*Mat6;
    //RPY(Mat7);
    cout<<"变换矩阵Mat7:= \n"<<Mat7<<endl;
    
    
    cout<<"test3-----"<<endl;
    Eigen::Matrix4d Mat9,Mat10,Mat11,Mat12;
    Mat9=goujianfangzhen(615,-35,698,0.0560427,0.565758,0.234345,0.788581);
    Mat10=Mat9.inverse();
    Mat11=goujianfangzhen(615,-35,708,0.0560427,0.565758,0.234345,0.788581);
    Mat12=Mat10*Mat11;
    //RPY(Mat11);
    cout<<"变换矩阵Mat12:= \n"<<Mat12<<endl;
    
    cout<<"test4-----"<<endl;
    Eigen::Matrix4d Mat13,Mat14,Mat15,Mat16;
    Mat13=goujianfangzhen(618,-84,681,0.02226,0.531976,0.200562,0.822363);
    Mat14=Mat13.inverse();
    Mat15=goujianfangzhen(618,-84,691,0.02226,0.531976,0.200562,0.822363);
    Mat16=Mat14*Mat15;
    //RPY(Mat15);
    cout<<"变换矩阵Mat16:= \n"<<Mat16<<endl;
    
    cout<<"test5-----"<<endl;
    Eigen::Matrix4d Mat17,Mat18,Mat19,Mat20;
    Mat17=goujianfangzhen(618,-81,584,-0.353553,0.707107,-1.75248e-08,0.612372);
    Mat18=Mat17.inverse();
    Mat19=goujianfangzhen(618,-81,594,-0.353553,0.707107,-1.75248e-08,0.612372);
    Mat20=Mat18*Mat19;
    //RPY(Mat20);
    cout<<"变换矩阵Mat20:= \n"<<Mat20<<endl;
    Mat8<<1,0,0,-9,
          0,1,0,0,
          0,0,1,0,
          0,0,0,1;

    //cout<<"方阵MAT1:= \n"<<Mat0*Mat8<<endl;
    
    return 0;
}
