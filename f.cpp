#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
Mat im=imread("joker.jpg",1);
Mat h(im.rows,im.cols,CV_8UC1,Scalar(0));
Mat n(im.rows,im.cols,CV_8UC1,Scalar(0));
int i,j,a,b,c;
for(i=0;i<im.rows;i++)
{
for(j=0;j<im.cols;j++)
{
a=im.at<Vec3b>(i,j)[0];
b=im.at<Vec3b>(i,j)[1];
c=im.at<Vec3b>(i,j)[2];
h.at<uchar>(i,j)=((0.114*a)+(0.587*b)+(0.299*c));
n.at<uchar>(i,j)=(a+b+c)/3;
}
}
namedWindow("IMG",WINDOW_NORMAL);
namedWindow("jj",WINDOW_NORMAL);
namedWindow("ii",WINDOW_NORMAL);
imshow("jj",im);
imshow("IMG",h);
imshow("ii",n);
waitKey(0);
}
