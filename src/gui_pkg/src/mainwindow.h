#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <QString>
namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_pushButton_clicked();

  void on_verticalSlider_valueChanged(int value);

private:
  Ui::MainWindow *ui;
  ros::Publisher chatter_publisher;
};

#endif // MAINWINDOW_H
