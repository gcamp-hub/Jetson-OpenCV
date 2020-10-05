#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
      Mat frame;

      VideoCapture cap("avi/video.mp4");

      if(!cap.isOpened())
      {
	cerr << "file open fail!" << endl;
 
	return -1;
      }

      while (1) 
      {
	cap >> frame;

	if (frame.empty()) 
	{
	     cerr << "empty frame" << endl;

	     break;
	}

	imshow("vid", frame);

	waitKey(33);

      }

      return 0;
}

