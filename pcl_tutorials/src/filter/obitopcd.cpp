#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/PolygonMesh.h>
#include <pcl/point_cloud.h>
#include <pcl/io/vtk_lib_io.h>//loadPolygonFileOBJ所属头文件；
 
using namespace pcl;
int main()
{
pcl::PolygonMesh mesh;
pcl::io::loadPolygonFileOBJ("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/fang.obj", mesh);
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
pcl::fromPCLPointCloud2(mesh.cloud, *cloud);
pcl::io::savePCDFileASCII("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/filter/fang.pcd", *cloud);
return 0;
}
