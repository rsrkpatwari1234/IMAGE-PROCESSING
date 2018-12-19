#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<queue>
using namespace cv;
using namespace std;
Mat a=imread("Binary1.png",0);
Mat b;
int Isval(int f,int h,int rows,int cols)
{
	if(f<0||h<0||f>=rows||h>=cols)
		return 0;
	return 1;
}
void bfs(int,int);
typedef struct
{
	int x;
	int y;
}index1;
int main()
{
	int i,j,count=0;
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
	 b=a.clone();
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			if(b.at<uchar>(i,j)==255)
			{
				count++;
				bfs(i,j);
			}
		}
	}
	cout<<"no. of structures = "<<count<<endl;
	return 0;
}

void bfs(int h,int k1)
{
	queue<index1> q;
	index1 c,m;
	c.x=h;
	c.y=k1;
	q.push(c);
	int i,j;
	while(!q.empty())
	{
		c=q.front();
		if(b.at<uchar>(c.x,c.y)==0)
		{
			q.pop();
			continue;
		}
		for(i=c.x-3;i<=c.x+3;i++)
		{
			for(j=c.y-3;j<=c.y+3;j++)
			{
				
				if((i!=c.x)&&(j!=c.y)&&Isval(i,j,b.rows,b.cols)==1&&(b.at<uchar>(i,j)!=0))
				{
					m.x=i;
					m.y=j;
					q.push(m);
				}
			}
		}
		b.at<uchar>(c.x,c.y)=0;
		q.pop();
		
	}
}














