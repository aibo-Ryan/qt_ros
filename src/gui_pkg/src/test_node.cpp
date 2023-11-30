#include <ros/ros.h>
#include "std_msgs/String.h"
#include"mainwindow.h"
#include<QApplication>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_node");
  ros::NodeHandle nh;

  ROS_INFO("Hello world!");
  QApplication a(argc,argv);
      MainWindow w;
      w.show();
      return a.exec();
}
