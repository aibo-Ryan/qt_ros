cmake_minimum_required(VERSION 3.0.2)
project(ryan_gui_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rviz
)
find_package(Qt5  REQUIRED COMPONENTS  Widgets )#寻找Qt的包

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)#上面这三行是在把Qt代码交给CMake之前必要的操作，具体作用我也不清楚

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ryan_gui_pkg
 CATKIN_DEPENDS roscpp rviz
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)
add_executable(main_node src/main.cpp src/mainwindow.cpp src/mainwindow.ui)

## Specify libraries to link a library or executable target against
 target_link_libraries(main_node
   ${catkin_LIBRARIES}
 )
target_link_libraries(main_node  Qt5::Widgets )#链接Qt库

 install(TARGETS main_node
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )
