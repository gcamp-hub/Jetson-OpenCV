#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

Mat input_image, edges;
const char* window_name = "Edge-Detection";
int lowThreshold, highThreshold;

void CannyThreshold(int, void*) {
    Canny(input_image, edges, lowThreshold, highThreshold, 3);
    imshow(window_name, edges);
}

int main()
{
    input_image = imread("images/Fig04_house.tif");
    cvtColor(input_image, input_image, cv::COLOR_BGR2GRAY);
    edges.create(input_image.size(), input_image.type());
    namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    createTrackbar("Threshold1", window_name, &lowThreshold,200, CannyThreshold); 
    createTrackbar("Threshold2", window_name, &highThreshold,255,CannyThreshold);
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}
