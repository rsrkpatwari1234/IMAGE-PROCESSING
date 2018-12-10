#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat a=imread("joker.jpg",1);
Mat b(a.rows*2,a.cols*2,CV_8UC3,Scalar(0,0,0));
int i,j,x,z,y,m=0,n;
for(i=0;i<a.rows*2;i=i+2)
{
n=0;
for(j=0;j<a.cols*2;j=j+2)
{
b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(m,n)[0];
b.at<Vec3b>(i+1,j)[0]=a.at<Vec3b>(m,n)[0];
b.at<Vec3b>(i,j+1)[0]=a.at<Vec3b>(m,n)[0];
b.at<Vec3b>(i+1,j+1)[0]=a.at<Vec3b>(m,n)[0];
b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(m,n)[1];
b.at<Vec3b>(i+1,j)[1]=a.at<Vec3b>(m,n)[1];
b.at<Vec3b>(i,j+1)[1]=a.at<Vec3b>(m,n)[1];
b.at<Vec3b>(i+1,j+1)[1]=a.at<Vec3b>(m,n)[1];
b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(m,n)[2];
b.at<Vec3b>(i+1,j)[2]=a.at<Vec3b>(m,n)[2];
b.at<Vec3b>(i,j+1)[2]=a.at<Vec3b>(m,n)[2];
b.at<Vec3b>(i+1,j+1)[2]=a.at<Vec3b>(m,n)[2];
n++;
}
m++;
}
for(i=0;i<a.rows*2-1;i++)
{
for(j=1;j<a.cols*2-2;j++)
{
x=(b.at<Vec3b>(i,j)[0]+b.at<Vec3b>(i+1,j)[0]+b.at<Vec3b>(i,j+1)[0]+b.at<Vec3b>(i+1,j+1)[0])/4;
y=(b.at<Vec3b>(i,j)[1]+b.at<Vec3b>(i+1,j)[1]+b.at<Vec3b>(i,j+1)[1]+b.at<Vec3b>(i+1,j+1)[1])/4;
z=(b.at<Vec3b>(i,j)[2]+b.at<Vec3b>(i+1,j)[2]+b.at<Vec3b>(i,j+1)[2]+b.at<Vec3b>(i+1,j+1)[2])/4;
b.at<Vec3b>(i,j)[0]=x;
b.at<Vec3b>(i+1,j)[0]=x;
b.at<Vec3b>(i,j+1)[0]=x;
b.at<Vec3b>(i+1,j+1)[0]=x;
b.at<Vec3b>(i,j)[1]=y;
b.at<Vec3b>(i+1,j)[1]=y;
b.at<Vec3b>(i,j+1)[1]=y;
b.at<Vec3b>(i+1,j+1)[1]=y;
b.at<Vec3b>(i,j)[2]=z;
b.at<Vec3b>(i+1,j)[2]=z;
b.at<Vec3b>(i,j+1)[2]=z;
b.at<Vec3b>(i+1,j+1)[2]=z;
}
}
imshow("df",a);
imshow("dg",b);
waitKey(0);
}

