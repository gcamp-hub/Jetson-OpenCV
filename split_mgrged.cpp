#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
      Mat img = imread("images/colorbar.jpg", IMREAD_COLOR);
 
      imshow("org", img);
      vector <Mat> channel; 
	  split (img, channel); 
	  char wname[10];
      
	  for (int i = 0; i < img.channels(); i++)
      {
            sprintf (wname, "ch%d", i);
            imshow (wname, channel[ i]);
      }

      Mat merged;
      channel[0] = channel[0]/2;
      channel[1] = channel[1]/2;
      merge(channel, merged);
      imshow("mrg", merged);

      waitKey(0);
}

