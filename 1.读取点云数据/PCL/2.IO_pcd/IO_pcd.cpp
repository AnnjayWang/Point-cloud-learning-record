#include <iostream>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>  // 用于pcd读取

int main()
{
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
 
    /** 1,读取点云数据 **/
    pcl::PCDReader reader;
    reader.read("ism_test.pcd", *cloud);
    std::cout << "原始点云的数量: "<< cloud->points.size() << std::endl;    

    return 0;
}