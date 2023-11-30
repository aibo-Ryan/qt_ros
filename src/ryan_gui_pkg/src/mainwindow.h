#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <QString>

#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(int argc, char **argv, QWidget *parent = nullptr);
  ~MainWindow();

  void init_ros(int argc, char **argv);

private slots:
  // void on_pushButton_clicked();

  // void on_verticalSlider_valueChanged(int value);
  void slot_btn_display();
  void slot_btn_quit();

private:
  Ui::MainWindow *ui;

  std::string map_topic = "/map";
  std::string laserscan_topic = "/scan";
  ros::Publisher chatter_publisher;
  rviz::VisualizationManager *manager_;
  rviz::RenderPanel *render_panel_;
};

#endif // MAINWINDOW_H
