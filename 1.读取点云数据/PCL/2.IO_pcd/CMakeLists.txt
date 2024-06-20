cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(IO_pcd)

find_package(PCL 1.11 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS} )

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (IO_pcd IO_pcd.cpp)

target_link_libraries (IO_pcd ${PCL_LIBRARIES})  
