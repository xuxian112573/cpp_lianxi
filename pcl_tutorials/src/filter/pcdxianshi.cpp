#include<iostream>
#include<pcl/point_types.h>
#include<pcl/filters/statistical_outlier_removal.h>//统计滤波
#include<pcl/io/pcd_io.h>
#include<pcl/visualization/cloud_viewer.h>//点云可视化

typedef pcl::PointCloud<pcl::PointXYZ> Cloud;
using namespace std;
int main(int argc,char **argv)
{
    //定义点云对象指针
    Cloud::Ptr cloud_ptr(new Cloud);
    Cloud::Ptr cloud_filtered_ptr(new Cloud);
    //读取点云文件
    pcl::PCDReader reader;
    reader.read("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/zhengfangti.pcd",*cloud_ptr);
    if(cloud_ptr==NULL){cout<<"PCD file read err"<<endl;return -1;}
    cout<<"PointCloud before filter 滤波前shuliang :"<<cloud_ptr->width*cloud_ptr->height
            <<" data points ("<<pcl::getFieldsList(*cloud_ptr)<<"."<<endl;
            
            
    //程序可视化
    pcl::visualization::CloudViewer viewer("pcd viewer");//显示窗口的名字
    viewer.showCloud(cloud_ptr);
    while(!viewer.wasStopped())
    {
    //
    }
    
    
    
    
    return 0;
}
