#include "pclviewer.h"
#include "ui_pclviewer.h"
#include <pcl/io/pcd_io.h>
#include <pcl/common/common_headers.h>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
// #include <pcl/features/normal_3d.h>
#include <pcl/common/common_headers.h>

PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("PCL viewer");

  // Setup the cloud pointer
  cloud.reset (new PointCloudT);
  pcl::io::loadPCDFile ("partition.pcd", *cloud);
  // The number of points in the cloud
  // cloud->points.resize (200);

  // The default color
  red   = 128;
  green = 128;
  blue  = 128;

  // Fill the cloud with some points
  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);

    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }

  // Set up the QVTK window
  viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
  ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
  viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
  ui->qvtkWidget->update ();

  // Connect "random" button and the function
  connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

  // Connect R,G,B sliders and their functions
  connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
  connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
  connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
  connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  // Connect point size slider
  connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

  viewer->addPointCloud<pcl::PointXYZRGBL> (cloud, "cloud");
  pSliderValueChanged (2);
  viewer->resetCamera ();
  ui->qvtkWidget->update ();
}

void
PCLViewer::randomButtonPressed ()
{
  printf ("Random button was pressed\n");

  // Set the new color
  for (size_t i = 0; i < cloud->size(); i++)
  {
    cloud->points[i].r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  }

  viewer->updatePointCloud<pcl::PointXYZRGBL> (cloud, "cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::RGBsliderReleased ()
{
  // Set the new color
  for (size_t i = 0; i < cloud->size (); i++)
  {
    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }
  viewer->updatePointCloud<pcl::PointXYZRGBL> (cloud, "cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::redSliderValueChanged (int value)
{
  red = value;
  printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::greenSliderValueChanged (int value)
{
  green = value;
  printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::blueSliderValueChanged (int value)
{
  blue = value;
  printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}
