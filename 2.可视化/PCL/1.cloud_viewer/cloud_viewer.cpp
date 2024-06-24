#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <iostream>


void visualization_CloudViewer(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    pcl::visualization::CloudViewer viewer("Cloud Viewer"); // 标题设置为Cloud Viewer
    viewer.showCloud(cloud);

	while (!viewer.wasStopped())
	{
		
	}

}


int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile ("ism_test.pcd", *cloud);    // 解引用智能指针

    std::cout << "原始点云数量: " << cloud->points.size() << std::endl;

    visualization_CloudViewer(cloud);
  
    return 0;
}