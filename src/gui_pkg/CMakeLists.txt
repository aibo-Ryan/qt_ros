cmake_minimum_required(VERSION 3.0.2)
project(gui_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)
find_package(Qt5  REQUIRED COMPONENTS  Widgets  )#寻找Qt的包

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)#上面这三行是在把Qt代码交给CMake之前必要的操作，具体作用我也不清楚

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES gui_pkg
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
 include
 include/gui_pkg
  ${catkin_INCLUDE_DIRS}
)


 add_executable(test_node src/test_node.cpp src/mainwindow.cpp src/mainwindow.ui)

## Specify libraries to link a library or executable target against
 target_link_libraries(test_node
   ${catkin_LIBRARIES}
 )
target_link_libraries(test_node  Qt5::Widgets )#链接Qt库

 install(TARGETS test_node
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

