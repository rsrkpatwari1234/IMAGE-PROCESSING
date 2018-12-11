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
	Mat a=imread("veg.jpg",0);
	Mat b = a.clone();
	int th = 1,i,j,y,m,n,p,q,t,k,min,ar[a.rows*a.rows];
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("size","window",&th, 11);

	while(1)
	{
		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				y=th;k=0;
				for(m=i-y;m<=i+y;m++)
				{
					for(n=j-y;n<=j+y;n++)
					{
						if(Isval(m,n,a.rows,a.cols)==1)
						{
								ar[k]=a.at<uchar>(m,n);
								k++;
						}
					}
				}
				for(p=0;p<k;p++)
				{
					min=p;
					for(q=p+1;q<k;q++)
					{
						if(ar[min]>ar[q])
						min=q;
					}
					t=ar[min];
					ar[min]=ar[p];
					ar[p]=t;
				}
				if(k%2==0)
					m=(ar[k/2]+ar[k/2-1])/2;
				else
					m=ar[(k-1)/2];
				b.at<uchar>(i,j)=m;
			}
		}
		imshow("window",b);
		waitKey(1);
	}
imshow("window",b);
waitKey(0);
}





				
