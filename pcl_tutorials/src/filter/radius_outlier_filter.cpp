/*
球半径滤波器
#include<pcl/filters/radius_outlier_removal.h>
球半径滤波器与统计滤波器相比更加简单粗暴
以某点为中心。画一个球计算落在该球内的点的数量，当数量大于给定值时，
则保留改点，数量小于给定值时则剔除该点。
此算法运行速度快，依次迭代留下的点一定是最密集的，
但是球的半径和球内点的数目都需要人工处理
RadiusOutlinerRemova比较适合剔除单个离群点
ConditionalRemoval比较灵活，可以根据用户设置的条件灵活过滤

*/
#include<iostream>
#include<pcl/point_types.h>
#include<pcl/io/pcd_io.h>
#include<pcl/filters/radius_outlier_removal.h>//球半径滤波器
#include<pcl/visualization/cloud_viewer.h>

//别名
typedef pcl::PointCloud<pcl::PointXYZ> Cloud;

using namespace std;
int main(int argc,char** argv)
{
    //定义点云对象指针
    Cloud::Ptr cloud_ptr(new Cloud());
    Cloud::Ptr cloud_filtered_ptr(new Cloud());
    
    //产生点云数据
    cloud_ptr->width=5;
    cloud_ptr->height=1;
    cloud_ptr->points.resize(cloud_ptr->width*cloud_ptr->height);
    for(size_t i=0;i<cloud_ptr->points.size();++i)
    {
        cloud_ptr->points[i].x=1024*rand()/(RAND_MAX+1.0f);
        cloud_ptr->points[i].y=1024*rand()/(RAND_MAX+1.0f);
        cloud_ptr->points[i].z=1024*rand()/(RAND_MAX+1.0f);
    }
    
    std::cerr<<"Cloud before filetering 半径滤波前： "<<std::endl;
    for (size_t i=0;i<cloud_ptr->points.size();i++)
    {
        std::cerr<<"  "<<cloud_ptr->points[i].x<<"  "
                        <<cloud_ptr->points[i].y<<"  "
                        <<cloud_ptr->points[i].z<<"  "<<std::endl;
    }
    
    //创建滤波器
    pcl::RadiusOutlierRemoval<pcl::PointXYZ> Radius;
    Radius.setInputCloud(cloud_ptr);
    Radius.setRadiusSearch(1.2);//0.8
    Radius.setMinNeighborsInRadius(2);//半径内最少需要2个点
    Radius.filter(*cloud_filtered_ptr);
    
    //输出滤波后的点云信息
    std::cout<<"Cloud after filetering 半径滤波后： "<<std::endl;
    for(size_t i=0;i<cloud_filtered_ptr->points.size();i++)
    {
        std::cerr<< "  "<<cloud_filtered_ptr->points[i].x<<"  "
                        <<cloud_filtered_ptr->points[i].y<<"  "
                        <<cloud_filtered_ptr->points[i].z<<"  "<<std::endl;
    }
    //程序可视化
    pcl::visualization::CloudViewer viewer("pcd viewer");
    viewer.showCloud(cloud_filtered_ptr);
    while(!viewer.wasStopped())
    {}
    return 0;
}



























