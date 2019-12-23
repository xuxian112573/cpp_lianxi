#include<iostream>
#include<pcl/ModelCoefficients.h>//模型系数
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include<pcl/sample_consensus/method_types.h>//随机样本一致性算法 方法类型
#include<pcl/sample_consensus/model_types.h>//随机样本一致性算法 模型算法
#include<pcl/segmentation/sac_segmentation.h>//随机样本一致性算法 分割方法

int main(int argc,char** argv)
{
    pcl::PointCloud<pcl::PointXYZ> cloud;//创建点云对象，用于存储点运数据
    //填充点云数据
    cloud.width=15;
    cloud.height=1;
    cloud.points.resize(cloud.width*cloud.height);
    
    //生成随机数据
    for(size_t  i=0;i<cloud.points.size();++i)
    {
        cloud.points[i].x=1024*rand()/(RAND_MAX+1.0f);
        cloud.points[i].y=1024*rand()/(RAND_MAX+1.0f);
        cloud.points[i].z=1;
    }
    
    //设置几个局外点
    cloud.points[0].z=2.0;
    cloud.points[3].z=-2.0;
    cloud.points[6].z=4.0;
    //显示点云数量和坐标信息
    std::cerr<<"Point cloud data: "<<cloud.points.size()<<" points"<<std::endl;
    
    for(size_t i=0;i<cloud.points.size();++i)
    {
        std::cerr<<" "<<cloud.points[i].x<<"  "
                      <<cloud.points[i].y<<"  "
                      <<cloud.points[i].z<<std::endl;
    }
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);//存储输出的模型系数
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);//存储内点，使用的点
    //创建分割对象
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    //可选设置
    seg.setOptimizeCoefficients(true);
    //必须设置
    seg.setModelType(pcl::SACMODEL_PLANE);//设置模型类别，检测平面
    seg.setMethodType(pcl::SAC_RANSAC);//设置方法（聚类或随机样本一致性）
    seg.setDistanceThreshold(0.01);
    seg.setInputCloud(cloud.makeShared());
    seg.segment(*inliers,*coefficients);//分割操作
    if (inliers->indices.size () == 0)//根据内点数量，判断是否成功
	{

    PCL_ERROR ("Could not estimate a planar model for the given dataset.");
		return (-1);
  }
	//显示模型的系数
  std::cerr << "Model coefficients: " << coefficients->values[0] << " " 
						<<coefficients->values[1] << " "
						<<coefficients->values[2] << " " 
						<<coefficients->values[3] <<std::endl;
	//显示估计平面模型过程中使用的内点
  std::cerr << "Model inliers: " << inliers->indices.size () << std::endl;
	for (size_t i = 0; i < inliers->indices.size (); ++i)
			std::cerr << inliers->indices[i] << "    " <<cloud.points[inliers->indices[i]].x << " "
								<<cloud.points[inliers->indices[i]].y << " "
								<<cloud.points[inliers->indices[i]].z << std::endl;

    
    
    
    
    
    
    
    
    
    return 0;
}

