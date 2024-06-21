import open3d as o3d
import numpy as np

def read_file(file_path):
    """read path to get pointcloud & np.array data"""
    points = []
    with open(file_path, 'r') as file:
        for line in file:
            # 假设每行数据以逗号分隔，且数据顺序为x,y,z(只读取前三列坐标即可)
            values = list(map(float, line.strip().split(',')))  # 逗号代表间隔是“,”
            points.append([values[0], values[1], values[2]])

    np_data = np.array(points)
    print("原始点云数量: %d"%np_data.shape[0])

    return np_data 

def display_point_cloud_with_open3d(points):  
    # 创建点云对象  
    pcd = o3d.geometry.PointCloud()  
    pcd.points = o3d.utility.Vector3dVector(points)  
      
    # 创建可视化窗口并添加点云  
    o3d.visualization.draw_geometries([pcd])  

def main():
    file_path = "E:\\github\\1.point cloud learning\\2.可视化\open3d\\1.visualization_txt\\airplane_0001.txt"

    np_data  = read_file(file_path)
    display_point_cloud_with_open3d(np_data)


if __name__ == '__main__':  
    main()