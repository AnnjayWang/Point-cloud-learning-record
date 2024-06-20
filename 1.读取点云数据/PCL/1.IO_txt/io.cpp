#include <iostream>
#include <fstream>  // 文件流相关定义声明

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>


/** 从txt文件中读取点云数据，这里只有X,Y,Z三坐标 **/
void creat_pointcloud_from_txt(const std::string& file_path, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) 
{
    std::ifstream file(file_path.c_str());  // 打开文件，.c_str将“file_path”转换为c风格字符串
    std::string line;   // 用于临时存储txt文件中的每一行数据。
    pcl::PointXYZ point;    // 用于读取txt文件中的点坐标
    if (file.is_open()) // 判断文件是否被打开
    {
        while(getline(file, line))  // 读取txt文件中的一行，默认遇到“/n”停止
        {
            std::stringstream ss(line); // 将这一行的字符串转换s为输入流，以便提取数据
            ss >> point.x;
            ss >> point.y;
            ss >> point.z;
            cloud->push_back(point);    // 将读取的数据添加进cloud中
        }   
        file.close();   // 关闭文件流
    }
    else    // 错误处理
    {
        std::cout << " 无法打开文件 " << std::endl;
    }
}


int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);

    creat_pointcloud_from_txt("chair.txt", cloud1);  // 读取txt文件

    std::cout << "点的数量：" << cloud1->points.size() << std::endl;

    return 0;

}

