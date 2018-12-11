#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat a=imread("fruits.png",1);
int i,j,x,y,k;
Mat b(a.rows,a.cols,CV_8UC3,Scalar(0,0,0));
for(i=0;i<a.rows;i++)
{
for(j=0;j<a.cols;j++)
{
x=(i-j)/1.414;
y=(i+j)/1.414;
if(x>0&&y<a.cols)
{
for(k=0;k<3;k++)
{
b.at<Vec3b>(x,y)[k]=a.at<Vec3b>(i,j)[k];
}
}
}
}
imshow("k",b);
waitKey(0);
}
