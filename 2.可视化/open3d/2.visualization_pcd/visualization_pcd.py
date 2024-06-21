import numpy as np
import open3d as o3d

'''  注: 此时不再是np格式, 而是使用open3d中一种点云格式, 更方便后续点云处理 '''
def read_file_pcd(file_path):

    """读取点云 pcd """
    pcd = o3d.io.read_point_cloud(file_path)

    return pcd

def main():
    
    pcd_filepath = 'E:\\github\\1.point cloud learning\\2.可视化\\open3d\\2.visualization_pcd\\pig_view.pcd'     

    pcd_cloud  = read_file_pcd(pcd_filepath)   

    print(pcd_cloud)

    o3d.visualization.draw_geometries([pcd_cloud])  


if __name__ == '__main__':  
    main()



