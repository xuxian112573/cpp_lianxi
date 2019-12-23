#include<iostream>
#include<pcl/point_types.h>
#include<pcl/filters/voxel_grid.h>
#include<pcl/io/pcd_io.h>
#include<pcl/visualization/cloud_viewer.h>
#include <pcl_conversions/pcl_conversions.h>
typedef pcl::PointCloud<pcl::PointXYZ> Cloud;
using namespace std;
int main(int argc,char** argv)
{
    //定义点云对象指针
    pcl::PCLPointCloud2::Ptr cloud2_ptr(new pcl::PCLPointCloud2());
    pcl::PCLPointCloud2::Ptr cloud2_filtered_ptr(new pcl::PCLPointCloud2());
    Cloud::Ptr cloud_filtered_ptr(new Cloud);
    
    //读取点云文件 填充点云对象
    pcl::PCDReader reader;
    reader.read("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400.pcd",*cloud2_ptr);
    if(cloud2_ptr==NULL)
    {   
        cout<<"pcd file read err "<<endl;
        return -1;
    }
    cout<<"pointCLOUND before filetering 滤波前： "<<cloud2_ptr->width*cloud2_ptr->height
                        <<" data points("<<pcl::getFieldsList(*cloud2_ptr)<<"."<<endl;
    //创建滤波对象
    pcl::VoxelGrid<pcl::PCLPointCloud2> vg;
    vg.setInputCloud(cloud2_ptr);//输入点云
    vg.setLeafSize(0.01f,0.01f,0.01f);//体素快大小1cm
    vg.filter(*cloud2_filtered_ptr);
    
    //输出滤波后的点云信息
    cout<<"pointCLOUND before filetering 滤波后的数量： "<<cloud2_filtered_ptr->width*cloud2_filtered_ptr->height<<" data points(" <<pcl::getFieldsList(*cloud2_filtered_ptr)<<"."<<endl;
    
    //写入内存
    pcl::PCDWriter writer;
    writer.write("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/table_scene_lms400_downsample.pcd",*cloud2_filtered_ptr,
                    Eigen::Vector4f::Zero(),Eigen::Quaternionf::Identity(),false);
    //调用系统可视化命令行显示
    //system("pcl_viewer table_scene_lms400_downsample.pcd");
    //转换成模板点云
    pcl::fromPCLPointCloud2(*cloud2_filtered_ptr,*cloud_filtered_ptr);
    
    
    //程序可视化
    pcl::visualization::CloudViewer viewer("pcd viewer");//窗口显示名字
    viewer.showCloud(cloud_filtered_ptr);
    while(!viewer.wasStopped())
    {
        //
    }
    return 0;
    
    
    
    
    
    
    
    
    
    
    
}
