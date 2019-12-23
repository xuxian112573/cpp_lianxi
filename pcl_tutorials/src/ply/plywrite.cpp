#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/common/io.h>
#include <pcl/impl/point_types.hpp>
#include <pcl/point_cloud.h>
 
 
int  main (int argc, char** argv) 
{ 
  pcl::PointCloud<pcl::PointXYZ> cloud; 
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr = pcl::PointCloud<pcl::PointXYZ>::Ptr (new pcl::PointCloud<pcl::PointXYZ>); 
  // Fill in the cloud data 
  cloud.width    = 50; 
  cloud.height   = 1; 
  cloud.is_dense = false; 
  cloud.points.resize (cloud.width * cloud.height); 
  
  cloud_ptr->width = cloud.width ; 
  cloud_ptr->height = cloud.height; 
  cloud_ptr->is_dense = cloud.is_dense; 
 // cloud_ptr->points.resize (cloud.width * cloud.height); 
 
  for (size_t i = 0; i < cloud.points.size (); ++i) 
  { 
   // cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f); 
   // cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f); 
   // cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f); 
 
        pcl::PointXYZ p; 
        p.x = 1024 * rand () / (RAND_MAX + 1.0f); 
        p.y = 1024 * rand () / (RAND_MAX + 1.0f); 
        p.z = 1024 * rand () / (RAND_MAX + 1.0f); 
        cloud.points[i].x = p.x; 
        cloud.points[i].y = p.y; 
        cloud.points[i].z = p.z; 
 
        cloud_ptr->points.push_back(p); 
  } 
  std::cerr << "Saving to pcd file " << std::endl; 
 //pcl::io::savePCDFileASCII ("test_pcd0.pcd", cloud); 
  pcl::io::savePCDFile ("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/ply/test_pcd1.pcd", *cloud_ptr); 
  std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl; 
 
  std::cerr << "Saving to ply file " << std::endl; 
  pcl::io::savePLYFile ("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/ply/test_ply.ply", cloud); 
 
  for (size_t i = 0; i < cloud.points.size (); ++i){ 
  //  std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl; 
          //std::cerr << "    " << cloud_ptr->points[i].x << " " << cloud_ptr->points[i].y << " " << cloud_ptr->points[i].z << std::endl; 
  } 
 
  return (0); 
} 
