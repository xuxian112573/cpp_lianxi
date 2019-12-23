/*
均匀采样：半径球内，保留一个点（重心点）
均匀采样：这个类基本是相同的，但它输出的点云索引是选择的关键点，是在计算描述子的常见方式。
原理同体素格：半径球内保留一个点（重心点）
*/
#include<iostream>
#include<pcl/point_types.h>
#include<pcl/keypoints/uniform_sampling.h>//均匀采样

#include<pcl/io/pcd_io.h>//点云文件pcd 读写
#include<pcl/visualization/cloud_viewer.h>//点云可视化
#include<pcl_conversions/pcl_conversions.h>//点云类型转换

/*
    cloudViewer是简单的显示点的可视化线程中运行代码的例子，
    PCLVisualizer是CloudViewer的后端，但在自己的线程中运行
    如果要使用PCLVisualizer类必须使用调用函数，这样可以避免可视化的并发问题。
    但实际调用的时候要注意

*/
using namespace std;
typedef pcl::PointCloud<pcl::PointXYZ> Cloud;

int main(int argc,char** argv)
{
    //定义点云对象指针
    Cloud::Ptr cloud_ptr(new Cloud);
    Cloud::Ptr cloud_filtered_ptr(new Cloud);
    
    //读取点云文件 填充点云对象
    pcl::PCDReader reader;
    reader.read("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400.pcd",*cloud_ptr);
    
    if(cloud_ptr==NULL){cout<<"pcd file read err"<<endl;return -1;}
    
    cout<<"pointCLOUND before filetering 滤波前： "<<cloud_ptr->width*cloud_ptr->height
                        <<" data points("<<pcl::getFieldsList(*cloud_ptr)<<"."<<endl;
     pcl::PointCloud<pcl::PointXYZ>::Ptr filteredCloud(new pcl::PointCloud<pcl::PointXYZ>);       
    //创建滤波对象
    //pcl::UniformSampling<pcl::PointXYZ> filter;//均匀采样
    pcl::UniformSampling<pcl::PointXYZ> filter;
    filter.setInputCloud(cloud_ptr);
    filter.setRadiusSearch(0.01f);//设置半径
    //pcl::PointCloud<int> keypointIndices;// 索引
    
    //filter.filter(*filteredCloud);
    //pcl::copyPointCloud(*cloud_ptr, keypointIndices.points, *cloud_filtered_ptr);
    //输出滤波后的点云信息
    cout<<"pointCLOUND before filetering 滤波后的数量： "<<cloud_filtered_ptr->width*cloud_filtered_ptr->height<<" data points(" <<pcl::getFieldsList(*cloud_filtered_ptr)<<"."<<endl;
    
}


















