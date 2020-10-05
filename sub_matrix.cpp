#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
      Mat image = imread("images/Bird.jpg", IMREAD_COLOR);

//      imshow("Output", image);

      Mat sub1(image, Rect(20, 30, 100, 200));
      Mat sub2(image, Rect(Point(120, 30), Point(220,230)));

      sub1 = Scalar(0, 255, 0); // sub1<- Green
      sub2 = Scalar(255, 255, 255); // sub2 <- White

      imshow("sub1", sub1);
      imshow("sub2", sub2);      
      imshow("org+sub", image);

      waitKey(0);

      return 0;
}

