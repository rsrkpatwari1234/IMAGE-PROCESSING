#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat a(320,320,CV_8UC3,Scalar(128,0,128));
int i,j,x,y;
for(i=0;i<320;i++)
{
for(j=0;j<320;j++)
{
x=i/40;
y=j/40;
if((x+y)%2==0)
{
a.at<Vec3b>(i,j)[0]=36;
a.at<Vec3b>(i,j)[1]=165;
a.at<Vec3b>(i,j)[2]=255;
}
}
}
namedWindow("window",WINDOW_NORMAL);
imshow("window",a);
waitKey(2000);
}
