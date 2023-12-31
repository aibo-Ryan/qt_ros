#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->lineEdit->setText(QString::number(ui->verticalSlider->value()));
  QObject::connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(on_verticalSlider_valueChanged(int)));

  int argc = 0;
  char **argv = NULL;
  ros::init(argc, argv, "client_plug");
  if (!ros::master::check())
  {
    ROS_INFO("No master started!");
    this->close();
  }
  ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
  chatter_publisher = n.advertise<std_msgs::String>("qtrostest_chat", 1000);
  // ros::spin();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  ROS_INFO(" CLICKED TRUE");
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
  ui->lineEdit->setText(QString::number(value));
  std_msgs::String msg;
  std::stringstream ss;
  ss << "data: " << ui->verticalSlider->value();
  msg.data = ss.str();
  chatter_publisher.publish(msg);
}
