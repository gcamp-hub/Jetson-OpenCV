#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;


int main() 
{
     Mat src = imread("images/Fig1034.tif" );

     //edge extraction
     Mat edge;
     Canny(src, edge, 80, 200, 3);
     
     //find contours
     vector<Vec4i> lines;
     HoughLinesP(edge, lines, 1, CV_PI / 180, 30, 50, 10);

     //draw lines
     for (size_t i = 0; i < lines.size(); i++)
     {
           line(src, Point(lines[i][0], lines[i][1]),Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 1);
     }

     imshow("Lines", src);
     waitKey(0); 

}
