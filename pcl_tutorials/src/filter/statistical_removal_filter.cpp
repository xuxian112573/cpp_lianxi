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
    reader.read("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400.pcd",*cloud_ptr);
    if(cloud_ptr==NULL){cout<<"PCD file read err"<<endl;return -1;}
    cout<<"PointCloud before filter 滤波前shuliang :"<<cloud_ptr->width*cloud_ptr->height
            <<" data points ("<<pcl::getFieldsList(*cloud_ptr)<<"."<<endl;
    //创建滤波器，对每个点分析的临近点的个数设置为50，并将标准差的倍数设置为1，这意味着如果一个点的距离
    //超出了平均距离一个标准差以上，则该点被标记为离群点，并将它移除，存储起来
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;//创建滤波对象
    sta.setInputCloud(cloud_ptr);//设置待滤波的点云
    sta.setMeanK(50);//设置在进行统计时考虑查询点临近点数
    sta.setStddevMulThresh(1.0);//设置判断是否为离群点的阈值
    sta.filter(*cloud_filtered_ptr);
    
    //输出滤波后的点云信息
    std::cerr<<"cloud after filetering: "<<std::endl;
    std::cerr<<*cloud_filtered_ptr<<std::endl;
    //写入内存 保存内点
    pcl::PCDWriter writer;
    writer.write("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400_inliers.pcd",*cloud_filtered_ptr,false);
    //保存外点被滤出的点
    sta.setNegative(true);
    sta.filter(*cloud_filtered_ptr);
    writer.write<pcl::PointXYZ>("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400_outliers.pcd",*cloud_filtered_ptr,false);
    
    //调用系统可视化命令行显示
    //system("pcl_viewer /home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400_inliers.pcd");
    //程序可视化
    pcl::visualization::CloudViewer viewer("pcd viewer");//显示窗口的名字
    viewer.showCloud(cloud_filtered_ptr);
    while(!viewer.wasStopped())
    {
    //
    }
    
    
    
    
    return 0;
}

