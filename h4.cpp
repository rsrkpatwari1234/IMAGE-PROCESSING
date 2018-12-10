# include "opencv2/highgui/highgui.hpp"
# include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat im=imread("lowcontrast.PNG",0);
int a[256],i,j,k,max=0;
for(i=0;i<256;i++)
	a[i]=0;		
for(i=0;i<im.rows;i++)
{
		for(j=0;j<im.cols;j++)
		{
			a[im.at<uchar>(i,j)]++;
		}
}
for(i=0;i<256;i++)
{
	if(max<a[i])
	max=a[i];
}
Mat img(max,256,CV_8UC1,Scalar(0));
for(j=0;j<256;j++)
{
	k=a[j];
	for(i=max-1;k>0;i--)
	{
			img.at<uchar>(i,j)=255;k--;
	}
}
imshow("k",img);
waitKey(0);
}
