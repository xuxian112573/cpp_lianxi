#include<iostream>
#include<Eigen/Core>
#include<Eigen/Geometry>

#define PI (3.1415926535897932346f)

int main(int argc,char **argv)
{
    using::std::cout;
    using::std::endl;
    double yaw= PI/2,pitching=2*PI/3,droll=PI/3;
   // Eigen::Quaterniond q;
    
    
    
    Eigen::Vector3d ea0(yaw,pitching,droll);
    Eigen::Matrix3d R;
    R=Eigen::AngleAxisd(ea0[0],Eigen::Vector3d::UnitZ())*Eigen::AngleAxisd(ea0[1],Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(ea0[2],Eigen::Vector3d::UnitX());
    cout<<"R:= "<<R<<endl;
    
    Eigen::Quaterniond q;
    
    q=R;
    cout<<"x:\n"<<q.x()<<endl;
    cout<<"y:\n"<<q.y()<<endl;
    cout<<"z:\n"<<q.z()<<endl;
    cout<<"w\n"<<q.w()<<endl;
    cout<<q.x()<<","<<q.y()<<","<<q.z()<<","<<q.w()<<endl;
    /*
    q.x()=0.65250;
    q.y()=-0.15267;
    q.z()=0.70182;
    q.w()=-0.24162;*/
    //四元数转旋转矩阵
    Eigen::Matrix3d Rx=q.toRotationMatrix();
    cout<<"RX=: "<<Rx<<endl;
    
    //旋转矩阵转欧拉角
    Eigen::Vector3d ea1=Rx.eulerAngles(2,1,0);
    cout<<ea1<<endl<<endl;
   // std::cin.ignore();
    
    
    return 0;
}
