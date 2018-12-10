#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
Mat a=imread("lena.png",1);
Mat b(a.rows,a.cols*2,CV_8UC3,Scalar(0,0,0));
int i,j,n,m;
for(i=0;i<a.rows;i++)
{
n=0;m=a.cols-1;
for(j=0;j<b.cols;j++)
{
if(j<b.cols/2)
{
b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,m)[0];
b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,m)[1];
b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,m)[2];
m--;
}
else
{
b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,n)[0];
b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,n)[1];
b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,n)[2];
n++;
}
}
}
imshow("kl",b);
waitKey(0);
}
