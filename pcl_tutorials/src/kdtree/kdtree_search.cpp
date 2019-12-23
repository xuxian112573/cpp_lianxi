#include<iostream>
#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>


#include <vector>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));//用系统时间初始化随机种子h
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    //产生随机点云
    cloud->width=10000;
    cloud->height=1;
    cloud->points.resize(cloud->width*cloud->height);
    for(size_t i=0;i<cloud->points.size();++i)
    {
        cloud->points[i].x=1024.0f*rand()/(RAND_MAX+1.0f);
        cloud->points[i].y=1024.0f*rand()/(RAND_MAX+1.0f);
        cloud->points[i].z=1024.0f*rand()/(RAND_MAX+1.0f);
    }
    cout<<"打印点云"<<endl;
    for(size_t i=0;i<cloud->points.size();++i)
    {
    //cout<<"点云个数： "<<cloud->width*cloud->height<<" x=: "<<cloud->points[i].x<<
                        //"  y=: "<<cloud->points[i].y<<"  z=: "<<cloud->points[i].z<<endl;
    }
    //创建kd-tree对象
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(cloud);//设置搜索空间、
    pcl::PointXYZ searchPoint;//定义查询点并赋值随机值
    searchPoint.x=1024.0f*rand()/(RAND_MAX+1.0f);
    searchPoint.y=1024.0f*rand()/(RAND_MAX+1.0f);
    searchPoint.z=1024.0f*rand()/(RAND_MAX+1.0f);
    
    //k近邻搜索
    int k=10;
    std::vector<int>pointIdxNKNSearch(k);//存储查询点近邻索引
    std::vector<float>pointNKNSquaredDistance(k);//存储紧邻点对应距离平方
    std::cout<<"K nearest neighbor search at ("<<searchPoint.x<<"  "<<searchPoint.y<<"  "<<searchPoint.z<<" )with k"<<k<<std::endl;
    
    //执行K近邻搜索
    if ( kdtree.nearestKSearch (searchPoint, k, pointIdxNKNSearch, pointNKNSquaredDistance) > 0 )
  {
    for (size_t i = 0; i < pointIdxNKNSearch.size (); ++i)
      std::cout << "    "  <<   cloud->points[ pointIdxNKNSearch[i] ].x 
                << " " << cloud->points[ pointIdxNKNSearch[i] ].y 
                << " " << cloud->points[ pointIdxNKNSearch[i] ].z 
                << " (squared distance: " << pointNKNSquaredDistance[i] << ")" << std::endl;
  }
  
  // Neighbors within radius search

  std::vector<int> pointIdxRadiusSearch;
  std::vector<float> pointRadiusSquaredDistance;

  float radius = 256.0f * rand () / (RAND_MAX + 1.0f);

  std::cout << "Neighbors within radius search at (" << searchPoint.x 
            << " " << searchPoint.y 
            << " " << searchPoint.z
            << ") with radius=" << radius << std::endl;
            
    if ( kdtree.radiusSearch (searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0 )
  {
    for (size_t i = 0; i < pointIdxRadiusSearch.size (); ++i)
      std::cout << "    "  <<   cloud->points[ pointIdxRadiusSearch[i] ].x 
                << " " << cloud->points[ pointIdxRadiusSearch[i] ].y 
                << " " << cloud->points[ pointIdxRadiusSearch[i] ].z 
                << " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
  }


  return 0;    
    
}
