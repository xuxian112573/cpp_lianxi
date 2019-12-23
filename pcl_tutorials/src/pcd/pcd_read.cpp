#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
main (int argc, char** argv)
{
    //创建一个PointCloud<pcl::PointXYZ>boost共享指针并进行实例化
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("bun01.pcd", *cloud) == -1) //* load the file打开文件
  {
    PCL_ERROR ("Couldn't read file bun01.pcd \n");
    return (-1);
  }
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (size_t i = 0; i < cloud->points.size (); ++i)
    std::cout <<i<<":     " <<"x: "<<cloud->points[i].x
              << " "    <<"y:" <<cloud->points[i].y
              << " "    <<"z: "<<cloud->points[i].z << std::endl;

  return (0);
}
