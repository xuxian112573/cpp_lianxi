#include <iostream> 
#include <pcl/io/pcd_io.h> 
#include <pcl/point_types.h> 
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>
 
int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
 
    if (pcl::io::loadPLYFile<pcl::PointXYZ>("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/ply/test_ply.ply", *cloud) == -1) //* load the file 
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        system("PAUSE");
        return (-1);
    }
    //pcl::StatisticalOutlierRemoval::applyFileter()
    pcl::visualization::CloudViewer viewer("Viewer");
    viewer.showCloud(cloud);
 
    //system("PAUSE");
    sleep(100);
    return (0);
}
