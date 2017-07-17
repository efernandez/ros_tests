cmake_minimum_required(VERSION 2.8.3)
project(test_async_spinner)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(test_no_async_spinner_node src/test_no_async_spinner_node.cpp)
target_link_libraries(test_no_async_spinner_node ${catkin_LIBRARIES})

add_executable(test_async_spinner_node src/test_async_spinner_node.cpp)
target_link_libraries(test_async_spinner_node ${catkin_LIBRARIES})
