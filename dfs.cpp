#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<stack>
using namespace cv;
using namespace std;
int Isval(int f,int h,int rows,int cols)
{
	if(f<0||h<0||f>=rows||h>=cols)
		return 0;
	return 1;
}
typedef struct
{
	int x;
	int y;
}val;
void dfs(int,int);
Mat a=imread("Binary1.png",0);
Mat b;
stack<val> s;
val m;
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
	for(i=0;i<b.rows;i++)
	{
		for(j=0;j<b.cols;j++)
		{
			if(b.at<uchar>(i,j)==255)
			{
				count++;
				dfs(i,j);
			}
		}
	}
	cout<<"no. of structures = "<<count<<endl;
	return 0;
}

void dfs(int h,int k)
{
	m.x=h;
	m.y=k;
	int i,j;
	s.push(m);
	b.at<uchar>(h,k)=150;
	if(s.empty())
	{
		return ;
	}
	else
	{
		m=s.top();
		if((Isval(h,k+1,b.rows,b.cols)==1)&& b.at<uchar>(h,k+1)==255)
		dfs(h,k+1);
		if((Isval(h+1,k,b.rows,b.cols)==1)&& b.at<uchar>(h+1,k)==255)
		dfs(h+1,k);
		if(Isval(h,k-1,b.rows,b.cols)==1&& b.at<uchar>(h,k-1)==255)
		dfs(h,k-1);
		if(Isval(h-1,k,b.rows,b.cols)==1&& b.at<uchar>(h-1,k)==255)
		dfs(h-1,k);
		if((Isval(h-1,k-1,b.rows,b.cols)==1)&& b.at<uchar>(h-1,k-1)==255)
		dfs(h-1,k-1);
		if((Isval(h-1,k+1,b.rows,b.cols)==1)&& b.at<uchar>(h-1,k+1)==255)
		dfs(h-1,k+1);
		if(Isval(h+1,k-1,b.rows,b.cols)==1&& b.at<uchar>(h+1,k-1)==255)
		dfs(h+1,k-1);
		if(Isval(h+1,k+1,b.rows,b.cols)==1&& b.at<uchar>(h+1,k+1)==255)
		dfs(h+1,k+1);
		s.pop();
	}
}
















