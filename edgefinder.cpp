#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<cmath>
using namespace cv;
using namespace std;
int Isval(int h,int k,int rows,int cols)
{
	if(h<0||k<0||h>rows||k>cols)
		return 0;
	return 1;
}
int main()
{
	Mat a=imread("lena.png",0);
	Mat b=a.clone();
	int i,j,sumx,sumy,x,y,t,th = 0,p=0,q=0,m,n;
	namedWindow("window",WINDOW_NORMAL);
	int sobelx[][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	int sobely[][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	createTrackbar("threshold","window",&th,254);
	createTrackbar("sx","window",&p,254);
	createTrackbar("sy","window",&q,254);
	while(1)
	{
		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				x=0;sumx=0;sumy=0;
				for(m=i-1;m<=i+1;m++)
				{
					y=0;
					for(n=j-1;n<=j+1;n++)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
							sumx=sumx+((a.at<uchar>(m,n))*sobelx[x][y]);
							sumy=sumy+((a.at<uchar>(m,n))*sobely[x][y]);
						}
						y++;
					}
					x++;
				}
			t=(int)sqrt((sumx*sumx)+(sumy*sumy));
			if(t>th)
				b.at<uchar>(i,j)=255;
			else if(abs(sumx)>p)
				b.at<uchar>(i,j)=255;
			else if(abs(sumy)>q)
				b.at<uchar>(i,j)=255;
			else
				b.at<uchar>(i,j)=0;
			}
		}
		imshow("window",b);
		waitKey(1);
	}
imshow("window",b);
waitKey(0);
}




