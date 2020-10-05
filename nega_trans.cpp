#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

vector<uchar> getLUT( ) {
vector<uchar> Table (256,0);
for(int i =0; i < 256; ++i)
Table[i] = (uchar)(255-i);
return Table;
}
void process_ImageNegative(Mat &M) {
vector<uchar> Table = get LUT ( );
for(int i = 0; i < M.rows; ++i)
for(int j = 0; j < M.cols; ++j)
M.at<uchar>(i,j) = Table[M.at<uchar>(i,j)];
}

int main()
{
      Mat image = imread("images/Bird.jpg", IMREAD_GRAYSCALE);
      Mat dst = img.clone();
      process_ImageNegative(dst);
      imshow(“input img”, img);
      imshow(“processed img”, dst);

      waitKey(0);

      return 0;
}

