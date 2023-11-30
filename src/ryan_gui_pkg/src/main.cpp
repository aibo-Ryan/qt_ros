#include <ros/ros.h>
#include "std_msgs/String.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ryan_gui");
    ros::NodeHandle nh;

    QApplication a(argc, argv);
    MainWindow w(argc, argv);
    w.show();
    return a.exec();
}
