import numpy as np

'''读取txt文件,此函数只读取txt前三行'''
def read_file(file_path):

    """读取点云 np.array data"""
    points = []
    with open(file_path, 'r') as file:
        for line in file:
            # 假设每行数据以逗号分隔，且数据顺序为x,y,z(只读取前三列坐标即可)
            values = list(map(float, line.strip().split(',')))  # 逗号代表间隔是“,”，根据实际情况进行修改
            points.append([values[0], values[1], values[2]])    # 这里只读取了前三列的数据，如果想读取后面的数据，自行添加values[3].....

    np_data = np.array(points)
    print("原始点云数量: %d"%np_data.shape[0])
  
    return np_data 


def main():
    
    txt_filepath = 'E:\\modelnet40_normal_resampled\\airplane\\airplane_0001.txt'     # 所用txt为modelnet40, 六列数据分别为: x,y,z,nx,ny,nz。

    np_data  = read_file(txt_filepath)

if __name__ == '__main__':  
    main()
