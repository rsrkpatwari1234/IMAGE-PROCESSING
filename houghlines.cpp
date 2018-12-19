#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("A5.png",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	int i,j,m,k,n,t;
	float d,r,p,x;
	if(a.rows>a.cols)
		d=1.414*a.rows;
	else
		d=1.414*a.cols;
	m=(int)d;
	Mat b1(360,m+1,CV_8UC1,Scalar(0));
	int bin[360][m+1];
	for(i=0;i<360;i++)
	{
		for(j=0;j<m+1;j++)
		{
			bin[i][j]=0;
		}
	}
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				for(k=0;k<360;k++)
				{
					r=k*3.14/180;
					p=(i*cos(r))+(j*sin(r));
					int y=0,m=0;
					n=(int)p;
					/*while(1)
					{
					if(n<y)
					{
					n=m-1;
					break;
					}
					y=y+2;
					m++;
					}*/
					bin[k][n]=bin[k][n]+1;b1.at<uchar>(k,n)=b1.at<uchar>(k,n)+5;
				}
			}
		}
	}
	 k=0;
	int max[360*(m+1)],angle[360*(m+1)],dis[360*(m+1)];
	for(i=0;i<360;i++)
	{
		for(j=0;j<m+1;j++)
		{
			if(bin[i][j]>0)
			{
			max[k]=bin[i][j];
			angle[k]=i;
			dis[k]=j;
			k++;
			}
		}
	}
        for(i=0;i<k;i++)
	{
		int j1=i;
		for(j=i+1;j<k;j++)
		{
			if(max[j]>max[j1])
			{
				j1=j;
			}}
					t=max[j1];
					max[j1]=max[i];
					max[i]=t;
					t=angle[j1];
					angle[j1]=angle[i];
					angle[i]=t;
					t=dis[j1];
					dis[j1]=dis[i];
					dis[i]=t;
        if(i==k-1)
	cout<<"kj"<<endl;
		
	}t=max[0];int ctr=0;
	for(i=0;i<k;i++)
	{
		if(ctr==20)break;
		if(i==0||t>max[i])
		{
			t=max[i];ctr++;
			for(j=0;j<a.cols;j++)
			{
				r=angle[i]*3.14/180;
				x=(dis[i]-(j*sin(r)))/cos(r);int h=(int)x;
				if(h>=0&&h<a.rows)
				{
				
					a.at<uchar>(h,j)=255;
				}
			}
		}
	}
	imshow("l",b1);imshow("l1",a);
	waitKey(0); 
	cout<<"fg";return 0;
}























