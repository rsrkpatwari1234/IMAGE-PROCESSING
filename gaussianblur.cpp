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
	int i,j,y,m,n,sum,x,low=0,high=0;
	namedWindow("window",WINDOW_NORMAL);
	for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				sum=0;
				for(m=i-1;m<=i+1;m++)
				{
					for(n=j-1;n<=j+1;n++)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							x=a.at<uchar>(m,n);
							if(m==i&&n==j)
								sum=sum+(int)(x/4);
							else if(m!=i&&n==j)
								sum=sum+(int)(x/8);
							else if(m==i&&n!=j)
								sum=sum+(int)(x/8);
							else
								sum	=sum+(int)(x/16);
						}
					}
				}
				b.at<uchar>(i,j)=sum;
			}
		}
		imshow("window",b);
		waitKey(0);
}

