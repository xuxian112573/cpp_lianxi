 
#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
 
#include <iostream>
#include <vector>
#include <ctime>
#include <string.h>
 
int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::PCDReader reader;   //读取PCD
	//读取文件 
	reader.read("/home/xu/Desktop/cpp_lianxi/src/pcl_tutorials/src/kdtree/square.pcd", *cloud);
	std::cout << "PointCloud before filtering has: " << cloud->points.size() << " data points." << std::endl;
    /*
    要用kd树找最近的几个点，要先创建变量，并且指定，要找最近几个点。
    查找点的坐标是自己设定的，但是一定要在自己的点云文件范围之内
    */ 
	//创建kdtree对象，并将读取到的点云设置为输入。
	pcl::KdTreeFLANN<pcl::PointXYZRGBA> kdtree;
	kdtree.setInputCloud(cloud);
 
	pcl::PointXYZRGBA searchPoint;
	searchPoint.x = 0;
	searchPoint.y = 0;
	searchPoint.z = 0;
 
	//可视化
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_plane2D(new pcl::visualization::PCLVisualizer("2D Viewer plane"));
	viewer_plane2D->addPointCloud<pcl::PointXYZRGBA>(cloud, "sample cloud - plane ");
	//将所有的点与查找点连线，每条线都需要有自己独立的的ID,不能有重复，所以需要定义符流来创建不同的ID
	std::string lineId = "line";
	std::stringstream ss;
	//这里有两个近邻查找，一个是查找最近的的K个点，一个是查找距离在某个范围内（某个半径R）之内的点(R最近邻)
	 //K nearest neighbor search
	int K = 20;
	
	std::vector<int> pointIdxNKNSearch(K);
	std::vector<float> pointNKNSquaredDistance(K);
	std::cout << "K nearest neighbor search at (" << searchPoint.x
		<< " " << searchPoint.y	<< " " << searchPoint.z	<< ") with K=" << K << std::endl;
	if (kdtree.nearestKSearch(searchPoint, K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0)
	{
		for (size_t i = 0; i < pointIdxNKNSearch.size(); ++i)
		{
			ss << i;
			lineId += ss.str();
			viewer_plane2D->addLine<pcl::PointXYZRGBA>(cloud->points[pointIdxNKNSearch[i]], searchPoint, 1, 58, 82, lineId);
			std::cout <<i<< "    " << cloud->points[pointIdxNKNSearch[i]].x << " " << cloud->points[pointIdxNKNSearch[i]].y
				<< " " << cloud->points[pointIdxNKNSearch[i]].z << " (squared distance: " << pointNKNSquaredDistance[i] << ")" << std::endl;
		}
	}
 
	// Neighbors within radius search
	//创建2个向量来存储有关近邻的信息。
	std::vector<int> pointIdxRadiusSearch;
	std::vector<float> pointRadiusSquaredDistance;
	float radius = 30;//近邻半径为0.05m
	
	std::cout << "Neighbors within radius search at (" <<"  "<< searchPoint.x	<< " " << searchPoint.y
		<< " " << searchPoint.z	<< ") with radius=" << radius << std::endl;
	if (kdtree.radiusSearch(searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0)
	{
		for (size_t i = 0; i < pointIdxRadiusSearch.size(); ++i) {
			ss << i;
			lineId += ss.str();
			viewer_plane2D->addLine<pcl::PointXYZRGBA>(cloud->points[pointIdxRadiusSearch[i]], searchPoint, 1, 58, 82, lineId);
			std::cout <<i<<"  "<< cloud->points[pointIdxRadiusSearch[i]].x << " " << cloud->points[pointIdxRadiusSearch[i]].y
				<< " " << cloud->points[pointIdxRadiusSearch[i]].z << " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
		}
	}
	while (!viewer_plane2D->wasStopped())
	{
		viewer_plane2D->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
 
	system("pause");
	return 0;
}
