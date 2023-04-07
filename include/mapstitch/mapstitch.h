#ifndef MAPSTITCH_H
#define MAPSTITCH_H

#include <stdio.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>

#define THRESHOLD 1000

using namespace cv;
using namespace std;

class StitchedMap
{
public:
    StitchedMap(Mat &img1, Mat &img2, float max_pairwise_distance);
    ~StitchedMap();

    Mat get_debug();
    Mat get_stitch();
    bool is_valid;

    float rot_rad, rot_deg, transx, transy, scalex, scaley;
    Mat image1, image2, H;
    Mat dscv1, dscv2;

private:
    vector<KeyPoint> kpv1, kpv2;
    vector<KeyPoint> fil1, fil2;
    vector<DMatch> matches, matches_filtered;
    vector<Point2f> coord1, coord2;
};

#endif // MAPSTITCH_H
