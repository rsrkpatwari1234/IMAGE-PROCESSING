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
	Mat a=imread("lena.png",0);
	Mat b = a.clone();
	int th = 1,i,j,y,m,n;
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("size","window",&th, 11);

	while(1)
	{
		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				y = th;
				int sum = 0;
				for(m=i-y;m<=i+y;m++)
				{
					for(n=j-y;n<=j+y;n++)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
							sum=sum+(a.at<uchar>(m,n));
					}
				}
			b.at<uchar>(i,j)=sum/((2*th + 1)*(2*th + 1));
			}
		}
	imshow("window",b);
	waitKey(1);
	}	
	imshow("window",b);
	waitKey(0);
}






