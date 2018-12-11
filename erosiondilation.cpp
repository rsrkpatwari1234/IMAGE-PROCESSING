#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;

int Isval(int f,int h,int rows,int cols)
{
	if(f<0||h<0||f>=rows||h>=cols)
		return 0;
	return 1;
}

int main()
{
	Mat a=imread("lenaTest3.jpg",0);
	Mat b = a.clone();
	int i,j,m,n,f=0;
	namedWindow("window",WINDOW_NORMAL);
	for(i=0;i<a.rows;i++)				//performing erosion on the image
	{
		for(j=0;j<a.cols;j++)
		{
			f=0;
			for(m=i-1;m<=i+1;m++)
			{
				for(n=j-1;n<=j+1;n++)
				{
					if(m!=i&&n!=j)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							if(a.at<uchar>(m,n)==0)
							{
								b.at<uchar>(m,n)=0;
								f=1;
								break;
							}
						}
					}
					if(f==1)
					break;
				}
				if(f==1)
				break;
			}
		}
	}
	for(i=0;i<a.rows;i++)				//performing dilation on the eroded image
	{
		for(j=0;j<a.cols;j++)
		{
			f=0;
			for(m=i-1;m<=i+1;m++)
			{
				for(n=j-1;n<=j+1;n++)
				{
					if(m!=i&&n!=j)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							if(b.at<uchar>(m,n)==255)
							{
								b.at<uchar>(m,n)=255;
								f=1;
								break;
							}
						}
					}
					if(f==1)
					break;
					}
				if(f==1)
				break;
			}
		}
	}
	imshow("window",b);
	waitKey(0);
}






















	
