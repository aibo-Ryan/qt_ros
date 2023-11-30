#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int argc, char **argv, QWidget *parent) : QMainWindow(parent),
                                                                 ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  init_ros(argc, argv);

  render_panel_ = new rviz::RenderPanel;
  manager_ = new rviz::VisualizationManager(render_panel_);
  render_panel_->initialize(manager_->getSceneManager(), manager_);
  manager_->initialize();
  // manager_->startUpdate();

  ui->verticalLayout->addWidget(render_panel_);

  QObject::connect(ui->pushButton_start, SIGNAL(clicked()), this, SLOT(slot_btn_display()));
  QObject::connect(ui->pushButton_quit, SIGNAL(clicked()), this, SLOT(slot_btn_quit()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

// void MainWindow::on_pushButton_clicked()
// {
//   ROS_INFO(" CLICKED TRUE");
// }

// void MainWindow::on_verticalSlider_valueChanged(int value)
// {
//   ui->lineEdit->setText(QString::number(value));
//   std_msgs::String msg;
//   std::stringstream ss;
//   ss << "data: " << ui->verticalSlider->value();
//   msg.data = ss.str();
//   chatter_publisher.publish(msg);
// }
void MainWindow::init_ros(int argc, char **argv)
{
  ros::init(argc, argv, "vizlib_test", ros::init_options::AnonymousName);
}

void MainWindow::slot_btn_display()
{
  static int i = 0;

  if (i % 2 == 0)
  {
    manager_->removeAllDisplays();

    rviz::Display *map = manager_->createDisplay("rviz/Map", "adjustable map", true);
    map->subProp("Topic")->setValue(map_topic.c_str());

    rviz::Display *robot = manager_->createDisplay("rviz/RobotModel", "adjustable robot", true);
    robot->subProp("Robot Description")->setValue("robot_description");

    rviz::Display *laser = manager_->createDisplay("rviz/LaserScan", "adjustable scan", true);
    laser->subProp("Topic")->setValue(laserscan_topic.c_str());
    laser->subProp("Size (m)")->setValue("0.1");

    manager_->startUpdate();
    ui->pushButton_start->setText("NonDisplay");
  }
  else if (i % 2 == 1)
  {
    manager_->stopUpdate();
    ui->pushButton_start->setText("Display");
  }
  i++;
}

void MainWindow::slot_btn_quit()
{
  this->close();
}
