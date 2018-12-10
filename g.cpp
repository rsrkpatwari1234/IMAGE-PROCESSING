#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
Mat im=imread("joker.jpg",0);
Mat m=imread("lena.png",0);
Mat iw=imread("scenery.jpg",0);
int i,j,a,b,c;
while(1)
{
for(i=0;i<im.rows;i++)
{
for(j=0;j<im.cols;j++)
{
if(im.at<uchar>(i,j)>100)
{
im.at<uchar>(i,j)=255;
}
else
im.at<uchar>(i,j)=0;
}
}
for(i=0;i<iw.rows;i++)
{
for(j=0;j<iw.cols;j++)
{
if(iw.at<uchar>(i,j)>100)
{
iw.at<uchar>(i,j)=255;
}
else
iw.at<uchar>(i,j)=0;
}
}
for(i=0;i<m.rows;i++)
{
for(j=0;j<m.cols;j++)
{
if(m.at<uchar>(i,j)>100)
{
m.at<uchar>(i,j)=255;
}
else
m.at<uchar>(i,j)=0;
}
}}
imshow("inm",im);
imshow("iw",m);
imshow("im",iw);
waitKey(0);
}

