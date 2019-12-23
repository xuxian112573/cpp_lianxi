/*
直通滤波器PassThrough
#include<pcl/filters/passthrough.h>
如果采用结构光扫描的方式采集点云，必然物体沿Z向分布较广
但xy向的分布处于有限范围内。
此时可使用直通滤波器，确定点云在x或y方向上的范围
可较快剪除离散点，达到第一步粗处理的目的

//创建点云对象  指针
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

//原始点云获取后进行滤波
pcl::PassThrough<pcl::PointXYZ> pass;//创建滤波对象
pass.setInputCloud(cloud);//设置点云
pass.setFilterFieldName("z");//滤波字段名称被设置为z轴方向
pass.setFilterLimits(0.0,1.0);//可接受范围为（0.0,1.0）
pass.setFilterLimitsNegative(true);//设置保留范围内还是滤波范围内
pass.filter(*cloud_filtered);//执行滤波，保存过滤结果在cloud_filtered

*/
#include<iostream>
#include<pcl/point_types.h>
#include<pcl/filters/passthrough.h>//直通滤波器PassThrough
#include<pcl/visualization/cloud_viewer.h>

typedef pcl::PointCloud<pcl::PointXYZ> Cloud;
int main(int argc,char** argv)
{
    //定义点云对象指针
    Cloud::Ptr cloud_ptr(new Cloud());
    Cloud::Ptr cloud_filtered_ptr(new Cloud());
    
    
    //产生点云数据
    cloud_ptr->width=5;
    cloud_ptr->height=1;
    
    cloud_ptr->points.resize(cloud_ptr->width*cloud_ptr->height);
    for(size_t i=0;i<cloud_ptr->points.size();i++)
    {
        cloud_ptr->points[i].x=1024*rand()/(RAND_MAX+1.0f);
        cloud_ptr->points[i].y=1024*rand()/(RAND_MAX+1.0f);
        cloud_ptr->points[i].z=1024*rand()/(RAND_MAX+1.0f);
    }
    std::cerr<<"cloud befor filtering 滤波前："<<std::endl;
    for(size_t i=0;i<cloud_ptr->points.size();i++)
    {
        std::cerr<<"  "<<i<<"  "
                        <<cloud_ptr->points[i].x<<"  "
                        <<cloud_ptr->points[i].y<<"  "
                        <<cloud_ptr->points[i].z<<"  "<<std::endl;
                    
    }
    
    //创建滤波对象
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(cloud_ptr);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.0,10);
    pass.setKeepOrganized(true);//保持有序点云结构
    pass.setFilterLimitsNegative(true);//标志为false时保留范围内的点
    pass.filter(*cloud_filtered_ptr);
    
    //输出滤波后的点云
    std::cerr<<"cloud after filtering 滤波后： "<<std::endl;
    for(size_t i=0;i<cloud_filtered_ptr->points.size();i++)
    {
        std::cerr<<"  "<<i<<"  "
                        <<cloud_filtered_ptr->points[i].x<<"  "
                        <<cloud_filtered_ptr->points[i].y<<"  "
                        <<cloud_filtered_ptr->points[i].z<<"  "<<std::endl;
    }
    
    //程序可视化
    pcl::visualization::CloudViewer viewer("pcd viewer");//窗口显示名字
    viewer.showCloud(cloud_filtered_ptr);
    while(!viewer.wasStopped())
    {
        //
    }
    return 0;
    
    
}

































