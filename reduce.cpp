#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat a=imread("fruits.png",1);
int x,y,i,j,m=0,n;
x=a.rows;
y=a.cols;
Mat b(x,y,CV_8UC3,Scalar(255,0,0));
for(i=0;i<a.rows;i=i+2)
{
n=0;
for(j=0;j<a.cols;j=j+2)
{
b.at<Vec3b>(m,n)[0]=(a.at<Vec3b>(i,j)[0]+a.at<Vec3b>(i,j+1)[0]+a.at<Vec3b>(i+1,j)[0]+a.at<Vec3b>(i+1,j+1)[0])/4;
b.at<Vec3b>(m,n)[1]=(a.at<Vec3b>(i,j)[1]+a.at<Vec3b>(i,j+1)[1]+a.at<Vec3b>(i+1,j)[1]+a.at<Vec3b>(i+1,j+1)[1])/4;
b.at<Vec3b>(m,n)[2]=(a.at<Vec3b>(i,j)[2]+a.at<Vec3b>(i,j+1)[2]+a.at<Vec3b>(i+1,j)[2]+a.at<Vec3b>(i+1,j+1)[2])/4;
n++;
}
m++;
}
imshow("i",a);
imshow("k",b);
waitKey(0);
}

