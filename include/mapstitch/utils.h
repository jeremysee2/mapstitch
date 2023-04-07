#pragma once

#include <opencv2/opencv.hpp>
#include <nav_msgs/OccupancyGrid.h>

cv::Mat occupancyGridToCvMat(const nav_msgs::OccupancyGrid * map);

nav_msgs::OccupancyGrid cvMatToOccupancyGrid(const cv::Mat * im);
