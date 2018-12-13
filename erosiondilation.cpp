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
	Mat a=imread("erosion.png",0);
	int i,j,m,n,f=0;
	namedWindow("window",WINDOW_NORMAL);
	for(i=0;i<a.rows;i++)				
	{
		for(j=0;j<a.cols;j++)
		{
		if(a.at<uchar>(i,j)>100)
			a.at<uchar>(i,j)=255;
		else
			a.at<uchar>(i,j)=0;
		}
	}
	Mat b = a.clone();
	for(i=0;i<a.rows;i++)				//performing erosion on the image
	{
		for(j=0;j<a.cols;j++)
		{
			f=0;
			for(m=i-2;m<=i+2;m++)
			{
				for(n=j-2;n<=j+2;n++)
				{
					if(m!=i&&n!=j)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							if(a.at<uchar>(m,n)==0)
							{
								b.at<uchar>(i,j)=0;
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
	a=b.clone();
	for(i=0;i<a.rows;i++)				//performing erosion 2 on the image
	{
		for(j=0;j<a.cols;j++)
		{
			f=0;
			for(m=i-2;m<=i+2;m++)
			{
				for(n=j-2;n<=j+2;n++)
				{
					if(m!=i&&n!=j)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							if(a.at<uchar>(m,n)==0)
							{
								b.at<uchar>(i,j)=0;
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
			for(m=i-2;m<=i+2;m++)
			{
				for(n=j-2;n<=j+2;n++)
				{
					if(m!=i&&n!=j)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							if(a.at<uchar>(m,n)==255)
							{
								b.at<uchar>(i,j)=255;
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






















	
