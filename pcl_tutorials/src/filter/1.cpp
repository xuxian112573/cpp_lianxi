#include <iostream>
 
#include <pcl/io/pcd_io.h>
 
#include <pcl/point_types.h>
 
#include <pcl/filters/voxel_grid.h>
 
#include <pcl/filters/statistical_outlier_removal.h>
 
#include <pcl/visualization/cloud_viewer.h>
 
#include <pcl/visualization/pcl_visualizer.h>
 
#include <pcl/keypoints/uniform_sampling.h>
 
#include <pcl/surface/mls.h>
 
 
 
int main(int argc, char** argv)
 
{
 
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
 
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered1(new pcl::PointCloud<pcl::PointXYZ>);
 
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2(new pcl::PointCloud<pcl::PointXYZ>);
 
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered3(new pcl::PointCloud<pcl::PointXYZ>);
 
 
 
// Fill in the cloud data
 
pcl::PCDReader reader;
 
// Replace the path below with the path where you saved your file
 
reader.read("rabbit_gra.pcd", *cloud); // Remember to download the file first!
 
std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height
 
<< " data points (" << pcl::getFieldsList(*cloud) << ")."<<std::endl;
 
 
 
// Create the filtering object
 
pcl::VoxelGrid<pcl::PointXYZ> sor;    // 创建滤波（下采样）对象
 
sor.setInputCloud(cloud);             //设置需要过滤的点云
 
sor.setLeafSize(0.1f, 0.1f, 0.1f);    //设置滤波时创建的体素体积为1cm的立方体
 
sor.filter(*cloud_filtered1);          //执行滤波处理，储存输出点云 
 
std::cerr << "PointCloud after filtering: " << cloud_filtered1->width * cloud_filtered1->height
 
<< " data points (" << pcl::getFieldsList(*cloud_filtered1) << ")."<<std::endl;
 
 
 
// Create the filtering object
 
pcl::UniformSampling<pcl::PointXYZ> sor2;    // 创建均匀采样对象
 
sor2.setInputCloud(cloud);             //设置需要过滤的点云
 
sor2.setRadiusSearch(0.01f);    //设置滤波时创建的体素体积为1cm的立方体
 
//sor2.filter(*cloud_filtered2);          //执行滤波处理，储存输出点云 
 
std::cerr << "PointCloud after filtering: " << cloud_filtered2->width * cloud_filtered2->height
 
      << " data points "<< std::endl;
 
 
 
pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ> sor3;
 
sor3.setInputCloud(cloud);
 
//建立搜索对象
 
pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree;
 
sor3.setSearchMethod(kdtree);
 
sor3.setSearchRadius(0.1);  //设置搜索邻域的半径为3cm
 
sor3.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ>::SAMPLE_LOCAL_PLANE);  // Upsampling 采样的方法有 DISTINCT_CLOUD, RANDOM_UNIFORM_DENSIT
 
sor3.setUpsamplingRadius(0.1); // 采样的半径是
 
sor3.setUpsamplingStepSize(0.02);// 采样步数的大小
 
sor3.process(*cloud_filtered3);
 
std::cerr << "PointCloud after filtering: " << cloud_filtered3->width * cloud_filtered3->height
 
<< " data points (" << pcl::getFieldsList(*cloud_filtered3) << ")." << std::endl;
 
//pcl::PCDWriter writer;
 
//writer.write("table_scene_lms400_downsampled.pcd", *cloud_filtered,
 
//Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(), false);
 
 
 
pcl::visualization::PCLVisualizer viewer("采样");
 
int v1(1);   //设置左右窗口
 
int v2(2);
 
int v3(3);
 
int v4(4);
 
viewer.createViewPort(0.0, 0.0, 0.5, 0.5, v1);
 
viewer.setBackgroundColor(0, 0, 0, v1);
 
 
 
viewer.createViewPort(0.5, 0.0, 1.0, 0.5, v2);
 
viewer.setBackgroundColor(0, 0, 0, v2);
 
 
 
viewer.createViewPort(0.0, 0.5, 0.5, 1.0, v3);
 
viewer.setBackgroundColor(0, 0, 0, v3);
 
 
 
viewer.createViewPort(0.5, 0.5, 1.0, 1.0, v4);
 
viewer.setBackgroundColor(0, 0, 0, v4);
 
 
 
// The color we will be using
 
float bckgr_gray_level = 0.0;  // Black    设置背景颜色
 
float txt_gray_lvl = 1.0 - bckgr_gray_level;
 
 
 
// Original point cloud is white
 
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_in_color_h(cloud, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl, (int)255 * txt_gray_lvl);
 
viewer.addPointCloud(cloud, cloud_in_color_h, "cloud_in_v1", v1);   //viewer.addPointCloud(cloud_in, cloud_in_color_h, "cloud_in_v2", v2);
 
 
 
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_green(cloud_filtered1, 20, 180, 20);      // 显示绿色点云
 
viewer.addPointCloud(cloud_filtered1, cloud_out_green, "cloud_out1", v2); 
 
 
 
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_orage(cloud_filtered2, 250, 128, 10);     //显示橘色点云
 
viewer.addPointCloud(cloud_filtered2, cloud_out_orage, "cloud_out2", v3);
 
 
 
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_purple(cloud_filtered3, 255, 0, 255);      //显示紫色点云
 
viewer.addPointCloud(cloud_filtered3, cloud_out_purple, "cloud_out3", v4);
 
 
 
//viewer.setBackgroundColor(bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v2);
 
viewer.setSize(1280, 1024);  // Visualiser window size
 
//viewer.showCloud(cloud_out);
 
while (!viewer.wasStopped())
 
{
 
viewer.spinOnce();
 
}
 
 
 
return (0);
 
}
 
 
 
/********************************************************/
